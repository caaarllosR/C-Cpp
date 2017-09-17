#include <stdio.h>

int main() {

    int N, p, num, menor;

    scanf("%d", &N);
    scanf("%d", &menor);
    p = 0;

    for(int i=1; i < N; i++){
        scanf("%d", &num);

        if(num < menor){
            menor = num;
            p = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", p);
}
