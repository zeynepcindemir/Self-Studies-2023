#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int p1[2]; // C => P
    int p2[2]; // P => C

    if (pipe(p1) == -1)
    {
        return 1;
    }
    if (pipe(p2) == -1)
    {
        return 1;
    }
    int pid = fork();
    if (pid == -1)
    {
        return 2;
    }

    if (pid == 0)
    {
        close(p1[0]); // read side
        close(p2[1]); // write side
        // Child process
        int x;
        if (read(p2[0], &x, sizeof(x)) == -1)
        {
            return 3;
        }
        printf("Received (Child) %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1)
        {
            return 4;
        }
        printf("Wrote (Child) %d\n", x);
        close(p1[1]);
        close(p2[0]);
    }
    else
    {
        close(p1[1]); // write side
        close(p2[0]); // read side
        // Parent process
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p2[1], &y, sizeof(y)) == -1)
        {
            return 5;
        }
        printf("Wrote (Parent) %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1)
        {
            return 6;
        }
        printf("Result is (Parent) %d\n", y);
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }
    return 0;
}
