#include <iostream>
#include <sstream>

using namespace std;

int main()
{
     int num;

     stringstream ss;

     ss<<"42";
     ss>>num;
     cout<<num;

     ss.clear();
     ss<<"54";
     ss>>num;
     cout<<" "<<num<<endl;

     return 0;
}
