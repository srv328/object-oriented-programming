
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h>
using namespace std;

double array(int n, double *array){
    for(int i = 0; i < n; i++){
        array[i] = (2000 - rand() % 3000)/10.00;
    }
    return *array;
}


int main()
{
    const int n = 30;
    double massiv[n];
    massiv[n] = array(n, massiv);
    for(int i = 0; i < n; i++){
        //massiv[i] = (2000 - rand() % 3000)/10.00;
        cout << massiv[i] << " ";
    }
    cout<<"\n";
    double summa;
    for(int i = 0; i < n; i++){
        if (massiv[i]>0) summa+=massiv[i];
    }
    double min = 1000000;
    double max = 0;
    int max_in, min_in;
    for(int i = 0; i < n; i++){
        if (abs(massiv[i])>max){
            max_in = i;
            max = abs(massiv[i]);
        }
        if (abs(massiv[i])<min){
            min_in = i;
            min = abs(massiv[i]);
        } 
    }
    double proizv = 1.00;
    if (max_in>min_in){
        for(int i = min_in; i <= max_in; i++){
            proizv*=massiv[i];
        }
    }
    else{
        for(int i = max_in; i <= min_in; i++){
            proizv*=massiv[i];
        }
    }
    cout<<endl<<"Сумма положительных элементов массива: "<<summa<<endl<<"Произведение элементов массива, расположенных между "<<max_in<<" и "<< min_in << " элементами: "<<proizv;
}
