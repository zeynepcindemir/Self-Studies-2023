#include <stdio.h>

//SEEK_SET: Beginning of file
//SEEK_CUR: Current position of the file pointer
//SEEK_END: End of file

int main()
{
    FILE *f;
    f = fopen("poem.txt", "w");
    fputs("SpongeBob    Squarepants", f);
    fseek(f, 6, SEEK_SET);
    fputs("Patrick", f);
    fclose(f);
    return 0;
}
