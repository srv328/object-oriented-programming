#include<iostream>
#include<math.h>

using namespace std;

double otvet(double x, int n){
    double proizv = 1;
    double y;
    y = x+(x/(7+x));
    for (int i = 4; i <= n; i++){
        proizv*=log(1+(x/(7+x))*sqrt(i));
        if (i==4){
            cout<<proizv<<endl;
        }
    }
    proizv*=y;
    return proizv;
}

int main()
{
    int n = 75;
    double x = 3.5;
    double proizv = otvet(x, n);
    cout<<proizv;
}