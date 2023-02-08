#include <stdio.h>
#include "f91.h"

int main (){
    int num;
    scanf("%d", &num);
    while(num != 0)
    {
        printf("f91(%d) = %d\n", num, f91(num));
        scanf("%d", &num);
    }
    return 0;
}