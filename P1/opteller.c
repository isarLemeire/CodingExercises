#include <stdio.h>

int main() {
    int testArray3[10] = { -2, 8, -102, 0, 4, 666, 5, 4, -7, 236 };

    int lenght = sizeof(testArray3)/sizeof(testArray3[0]);
    int sum = 0;

    for(int i =0; i< lenght; i++){
        sum += testArray3[i];
    }
    printf("The sum equal %d\n", sum);

    int positive_sum = 0;

    for(int i =0; i< lenght; i++){
        testArray3[i] = (testArray3[i] > 0) ? testArray3[i] : -testArray3[i] ;
        printf("%d ", testArray3[i]);
        positive_sum += testArray3[i];
    }
    printf("\n");
    printf("The sum of all the positive elements equals %d\n", positive_sum);
    
}
