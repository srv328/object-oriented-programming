#include <iostream>
#include <string>
using namespace std;

void to_lower(char a) {
    if (a <= 'Z' && a >= 'A')
    {
        a += 'a' - 'A';
        cout << a;
    }
    else {
        cout << a;
    }
}


int main()
{
    string stroka;
    getline(cin, stroka);
    int i = 0;
    while (stroka[i]!=0) {
        to_lower(stroka[i]);
        i++;
    }
}