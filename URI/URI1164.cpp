#include <stdio.h>

int main(){

    int n, num, m, np = 0, p, n2;
    scanf("%d", &n);

    for(int i = 0; i<n ; i++){
            scanf("%d", &num);
        if(num%2!=0){
            printf("%d nao eh perfeito\n", num);
        }else{
            n2 = (num/2)+1;
            p = 0;
            np = 1;
            for(int j = 2; j<n2 ; j++){
                m = num%j;
                if(m==0){
                    np += j;
                }
            }
            if(np==num){
                printf("%d eh perfeito\n", num);
            }else{
                printf("%d nao eh perfeito\n", num);
            }
        }
    }
        return 0;
}
