#include <stdio.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string numToString(int n){
    int m = 0, i = 0, countN = 0;
    string s;

    if(n>0){
        while (n>0){

            m = n%10;
            n = n/10;

            s.push_back('0'+m);
            i++;
        }
        reverse(s.begin(),s.end());
    }else{
        s.push_back('0');
    }
    return s;
}

int main () {

    int n;
    scanf("%d", &n);
    string ss;

    string s = numToString(n);
    ss = '0'+9;
    s.append(ss);
    printf("%s", s.c_str());

}
