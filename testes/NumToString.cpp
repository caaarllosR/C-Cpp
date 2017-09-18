#include <stdio.h>
#include <string>
#include <algorithm>

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
    string s = numToString(n);
    s.erase(s.begin()+2);
    s.insert(s.begin()+2,3+48);
    printf("%s", s.c_str());

}
