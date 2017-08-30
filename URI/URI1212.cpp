#include <stdio.h>

int main(){

    int auxn, auxm, n, m, c = 0, ct = 0;

    scanf("%d %d", &m, &n);

    while((m>0)||(n>0)){

        while((m>0)||(n>0)){
            auxm = m%10;
            m = m/10;

            auxn = n%10;
            n = n/10;

            if((auxm+auxn+c)>=10){
                c = 1;
                ct++;
            }else{
                c = 0;
            }
        }
        if(ct==1){
            printf("%d carry operation.\n", ct);
        }else if (ct>1){
            printf("%d carry operations.\n", ct);
        }else{
            printf("No carry operation.\n");
        }

        ct = 0;
        c = 0;
        scanf("%d %d", &m, &n);
     }

     return 0;
}

