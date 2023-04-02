#include <stdio.h>

int main() {
    
    int* ages;
    int n = 4;
    
    ages = (int*)malloc(n * sizeof(int));
    
    if(ages == NULL) {
        printf("Memory cannot be allocated");
        return 0;
    }
    
    printf("Enter input values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", ages+i);
    }
    
    printf("Input Values are:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\n", *(ages + i));
    }
    
    n = 6;
    
    ages[4] = 32;
    ages[5] = 49;
    
    ages = realloc(ages, n * sizeof(int));
    
    printf("After reallocation:\n");
    for(int i = 0; i < n; ++i) {
        printf("%d\n", *(ages+i));
    }
    
    free(ages);
    return 0;
}
