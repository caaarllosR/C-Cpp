#include <stdio.h>

int main() {

	int k2 = 0, k1 = 0, valor1, valor2, r = 0;

    scanf("%d", &valor1);
    scanf("%d", &valor2);

    k1 = valor1;
    k2 = valor2;

    if (valor2 < valor1) {
        k1 = valor2;
        k2 = valor1;
    }

    k1 = k1+1;

    while (k1 < k2) {


        if ((k1 % 2) != 0) {
            r+=k1;
        }
        k1++;
    }
    printf("%d\n", r);

    return 0;
}
