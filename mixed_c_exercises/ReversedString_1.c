#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    char tmp[100];
    printf("Please enter a string: ");
    fgets(str,sizeof(str),stdin);

    for (size_t i = 0; i < strlen(str); i++)
    {
        *(tmp + strlen(str) - i - 1) = *(str + i);
    }
    tmp[strlen(str)] = '\0';

    for (size_t i = 0; i < strlen(tmp); i++)
    {
        printf("%c", *(tmp + i));
    }

    return 0;
}
