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

    char *left = str; // pointer to left end of string
    char *right = str + len - 1; // pointer to right end of string

    while (left < right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;

        left++;
        right--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
