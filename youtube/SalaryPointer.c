#include <stdio.h>

int main() {
    
    double salary, *sPtr;
  
    printf("Please enter your salary : ");
    scanf("%lf", &salary);
    sPtr = &salary;
  
    printf("Your Salary: %.2lf\n", *sPtr);
    *sPtr *= 2;
  
    printf("Your Doubled Salary: %.2lf\n", *sPtr);
    

    return 0;
}
