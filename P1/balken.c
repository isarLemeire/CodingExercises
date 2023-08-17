#include <stdio.h>
#include "balk.h"
#include "balk_functies.h"

int main() {
    balk balk;
    balk.l = 5;
    balk.h = 2;
    balk.b = 4;

    printf("Volume is %d\n", volume(balk));

    
    printf("Area is %d\n", area(balk));


    return 0;
}
