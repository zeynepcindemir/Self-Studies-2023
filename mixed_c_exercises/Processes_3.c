#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_LENGTH 256

int main()
{
    char buf[MAX_LENGTH];

    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    int pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 2;
    }
    if (pid == 0)
    {
        // child process
        close(fd[1]); // close write side of pipe

        printf("Child PID: %d, PPID: %d, GID: %d\n", getpid(), getppid(), getpgid(getpid()));

        if (read(fd[0], buf, sizeof(buf)) == -1)
        {
            perror("read");
            return 3;
        }

        // reverse the input string
        size_t len = strlen(buf);
        for (size_t i = 0; i < len / 2; i++)
        {
            char temp = buf[i];
            buf[i] = buf[len - i - 1];
            buf[len - i - 1] = temp;
        }

        printf("Child reversed string: %s\n", buf);

        close(fd[0]);
    }
    else
    {
        // parent process
        close(fd[0]); // close read side of pipe

        printf("Parent PID: %d, PPID: %d, GID: %d\n", getpid(), getppid(), getpgid(getpid()));

        sleep(1);
        printf("Please enter a string: \n");
        fgets(buf, sizeof(buf), stdin);
        
        if (write(fd[1], buf, strlen(buf) + 1) == -1)
        {
            perror("write");
            return 4;
        }

        close(fd[1]); // close write side of pipe

        wait(NULL); // wait for child process to finish
    }

    return 0;
}
