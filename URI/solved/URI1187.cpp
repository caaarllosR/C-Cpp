#include <stdio.h>

int main() {

    double Matriz[12][12], total = 0;;
    char c;

    scanf("%c", &c);

    for(int i=0; i < 12; i++){
        for(int j=0; j < 12; j++){
            scanf("%lf", &Matriz[i][j]);
        }
    }

    for(int i=0; i < 5; i++){
        for(int j=i+1; j < 11-i; j++){
            total+=Matriz[i][j];
        }
    }

    if (c=='S'){
        printf("%.1lf\n", total);
    }else {
        printf("%.1lf\n", total/30);
    }

    return 0;
}
