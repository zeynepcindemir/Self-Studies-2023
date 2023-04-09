
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

void child_process(int read_pipe[], int write_pipe[]) {
    char received_string[MAX_INPUT_SIZE];
    int len;

    // Çocuk işlemi, okuma ve yazma pipe'larını düzgün bir şekilde kapatır.
    close(read_pipe[1]);
    close(write_pipe[0]);

    // Ebeveyn işleminden string okuma
    read(read_pipe[0], &len, sizeof(int));
    read(read_pipe[0], received_string, len);

    // Okunan string'i ters cevir (XOR) - {Ekstra INT TEMP ve CHAR ARRAY kullanmadan} - [IN-PLACE]
    int start = 0;
    int end = len - 1;

    while (start < end) {
        received_string[start] ^= received_string[end];
        received_string[end]   ^= received_string[start];
        received_string[start] ^= received_string[end];

        start++;
        end--;
    }
    
    // Ters cevrilen string'i büyük harfe dönüştürme - [IN-PLACE]
    for (int i = 0; i < len; ++i) {
        received_string[i] = toupper(received_string[i]);
    }

    // Dönüştürülen string'i ebeveyn işlemine yazma
    write(write_pipe[1], &len, sizeof(int));
    write(write_pipe[1], received_string, len);

    // Çocuk işlemi sonlandırılır.
    exit(0);
}

int main() {
    int parent_to_child_pipe[2], child_to_parent_pipe[2];
    char input_string[MAX_INPUT_SIZE], result_string[MAX_INPUT_SIZE];
    int len;

    // İki pipe oluşturuluyor
    if (pipe(parent_to_child_pipe) == -1 || pipe(child_to_parent_pipe) == -1) {
        perror("pipe");
        exit(1);
    }

    // Fork kullanarak çocuk işlemi oluşturma
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Çocuk işlemi
        child_process(parent_to_child_pipe, child_to_parent_pipe);
    } else { // Ebeveyn işlemi
        // Ebeveyn işlemi, okuma ve yazma pipe'larını düzgün bir şekilde kapatır.
        close(parent_to_child_pipe[0]);
        close(child_to_parent_pipe[1]);

        // Kullanıcıdan string alınır
        printf("Bir string girin: ");
        fgets(input_string, MAX_INPUT_SIZE, stdin);

        // String'in uzunluğunu hesapla ve '\n' karakterini kaldır
        len = strlen(input_string) - 1;
        input_string[len] = '\0';

        // String'i çocuk işlemine yazma
        write(parent_to_child_pipe[1], &len, sizeof(int));
        write(parent_to_child_pipe[1], input_string, len);

        // Çocuk işleminden dönüşüm sonucunu okuma
        read(child_to_parent_pipe[0], &len, sizeof(int));
        read(child_to_parent_pipe[0], result_string, len);
        result_string[len] = '\0';

        // Dönüşüm sonucunu ekrana yazdırma
        printf("Dönüştürülen string: %s\n", result_string);

        // Ebeveyn işlemi, çocuk işleminin bitişini bekler
        wait(NULL);
    }

    return 0;
}
