#include <stdio.h>

int main() {

    int n, i=0, coelhos = 0, ratos = 0, sapos = 0, quantia, total = 0;
    char tipo;

    scanf("%d", &n);

    while (i < n) {

        scanf("%d %c", &quantia, &tipo);

        if (tipo=='C') {
            coelhos += quantia;
        }
        if (tipo=='R') {
            ratos += quantia;
        }
        if (tipo=='S') {
            sapos += quantia;
        }
        i++;
    }
    total = sapos+coelhos+ratos;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n",((100.0*coelhos)/total));
    printf("Percentual de ratos: %.2f %%\n",((100.0*ratos)/total));
    printf("Percentual de sapos: %.2f %%\n",((100.0*sapos)/total));

    return 0;
}
