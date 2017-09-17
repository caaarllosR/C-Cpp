#include <stdio.h>

int main() {

    int c, l = 144, j = 0;
    float n, soma = 0;;
    char t;

    scanf("%d %c", &c, &t);

    c = c + 1;
    for(int i=0; i < c; i++){
        scanf("%f", &n);
    }

    soma += n;

    for(int i=c; i < l; i++){
        scanf("%f", &n);

        j++;
        if(j==12){
            soma+=n;
            j = 0;
        }
    }

    if (t=='S'){
        printf("%.1f\n", soma);
    }else {
        printf("%.1f\n", soma/12);
    }

    return 0;
}
