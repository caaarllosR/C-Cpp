
#include <stdio.h>
#include <math.h>

int main(){
     int p1, p2, n;
     double h, teta, v, A, ts, td, t, vx, vy, hmax, g = 9.80665, pi = 3.14159;

    while(scanf("%lf %d %d %d", &h, &p1, &p2, &n)!=EOF){

        for(int i = 0; i<n;i++){

            scanf("%lf %lf", &teta, &v);

            teta = teta*pi/180;

            vy = v*sin(teta);
            vx = v*cos(teta);

            hmax = (pow(vy,2)/(2*g))+h;

            ts = vy/g;
            td = sqrt((hmax)*2/g);
            t = ts+td;

            A = vx*t;

            if(A>=p1 && A<=p2){
                printf("%.5lf -> DUCK\n", A);
            }else{
                printf("%.5lf -> NUCK\n", A);
            }
        }
     }
     return 0;
}
