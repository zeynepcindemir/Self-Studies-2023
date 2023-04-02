
#include <stdio.h>

int main() {
    
    typedef enum day{
        Sunday = 7,
        Monday = 1,
        Tuesday = 2,
        Wednesday = 3,
        Thursday = 4,
        Friday = 5,
        Saturday = 6
    
    }day;
    
    day weekend1,weekend2;
    weekend1 = Sunday;
    weekend2 = Saturday;
    printf("Weekend1 = %d, Weekend2 = %d", weekend1, weekend2);
    
    
    
    return 0;
}
