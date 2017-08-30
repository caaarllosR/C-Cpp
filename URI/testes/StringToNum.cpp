#include <stdio.h>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <cstdio>
#include <deque>

using namespace std;

class TestClass{
public:
    deque <int> dNum;

public:
     void splitNumber(string s){

        int i = 0;
        int l = 0;
        int n = 0;
        char c;

        l = s.size();

        while(i<l){
            c = s[i];
            if((c!=' ')){
                n = n*10 + c-48;
            }
            else{
                dNum.push_back(n);
                n = 0;
            }
            i++;
        }
        dNum.push_back(n);
    }
};
int main () {

    TestClass test;
    test.splitNumber("87 4 5 87 3 5 66");
    int sizeD = test.dNum.size();

        for (int j = 0; j<sizeD; j++)
    {
        printf("%d ", test.dNum.front());
        test.dNum.pop_front();
    }

}
