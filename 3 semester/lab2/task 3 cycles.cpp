
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int main()
{
    for (int x=1; x<=4; x++){
        cout<<"Ответ при x = "<<x<<": ";
        double summa = 5*x;
        int m = 15;
        for (int k=1; k<=m; k++){
            summa += ((double)x/(double)k)+((double)k/(double)x);
        }    
        double summa1;
        for (int i=1; i<=m; i++){
            summa1 += i*i;
        }  
        summa1*=x;
        cout<<summa+summa1<<endl;
    }
}
