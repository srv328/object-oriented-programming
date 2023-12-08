#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    float a,b,c;
    cin>>a>>b>>c;
    cout<<"Медиана a: "<<sqrt(2*b*b+2*c*c-a*a)/2<<endl;
    cout<<"Медиана b: "<<sqrt(2*a*a+2*c*c-b*b)/2<<endl;
    cout<<"Медиана c: "<<sqrt(2*b*b+2*a*a-c*c)/2<<endl;
}
