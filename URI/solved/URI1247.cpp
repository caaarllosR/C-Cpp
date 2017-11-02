#include <stdio.h>
#include <math.h>

int main(){
     int vf, vg, dx;
     float dg, df = 12.0, tg, tf;

    while(scanf("%d %d %d", &dx, &vf, &vg)!=EOF){

        dg = sqrt(dx*dx + 144);

        tg = dg/vg;
        tf = df/vf;

        if(tg <= tf){
            printf("S\n");
        }else {
            printf("N\n");
        }
     }
     return 0;
}
