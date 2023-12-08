#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    float y,z;
    double x;
    cout<<"Введите х: ";
    cin>>x;
    cout<<"y = "<<((1-x*x)/(1+x*x))*sqrt(x)<<endl;
    cout<<"z = "<<(abs(x)+abs(y))/(x-y)+abs(x/y);
}
