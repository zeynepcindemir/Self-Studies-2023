#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    char *token;
  
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
   
    token = strtok(s, " ");
    
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    
    free(s);
    return 0;
}
