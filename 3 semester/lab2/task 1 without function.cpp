
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n = 75;
    double x = 3.5;
    double y;
    y = x+(x/(7+x));
    double proizv = 1;
    for (int i = 4; i <= n; i++){
        proizv*=log(1+(x/(7+x))*sqrt(i));
        if (i==4){
            cout<<proizv<<endl;
        }
    }
    cout<<proizv*y;
}
