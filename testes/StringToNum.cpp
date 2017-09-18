#include <stdio.h>
#include <string>       // std::string
#include <iostream>     // std::cout

using namespace std;


int stringToNum(string s){

    int i = 0, l = 0, n = 0;
    char c;

    l = s.size();

    while(i<l){
        n = n*10 + s[i]-48;
        i++;
    }
    return n;
}

int main () {

    int n;
    string s;

    cin >> s;
    n = stringToNum(s);

    printf("%d", n);

}
