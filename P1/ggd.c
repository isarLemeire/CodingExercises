#include <stdio.h>

int ggd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char **argv) {
    int first, second;
    printf("\nDit programma berekent de grootste gemene deler van 2 positieve gehele getallen.\n\n");
    printf("getal 1: ");
    scanf("%d", &first);
    printf("\ngetal 2: ");
    scanf("%d", &second);
    printf("\n\nGGD %3d \n\n", ggd(first, second));
    return 0;
}
