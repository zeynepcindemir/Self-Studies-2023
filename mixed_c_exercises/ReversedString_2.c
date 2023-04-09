#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    printf("Please enter a string: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[--len] = '\0'; // remove newline character if present
    }

    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
