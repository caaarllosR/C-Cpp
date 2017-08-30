#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>

using namespace std;


string numString(int n){
    int m = 0;
    string s;

    m = n%10;
    n = n/10;

    while (n>0){

        m = m*10 + n%10;
        n = n/10;
    }

    while (m>0){

        n = m%10;
        m = m/10;

        s.push_back('0'+n);
    }

    return s;
}

int main () {

    int n = 527526787;
    string s = numString(n);
    printf("%s", s.c_str());

}
