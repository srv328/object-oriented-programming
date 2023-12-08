#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int count = 0;
    string s;
    cout << "Введите текст: ";
    getline(cin, s);
    stringstream strm(s);
    for (string i;strm >> i;)
        if (i[0] == i[i.length() - 1])
            count++;
    cout << "Количество слов, которые начинаются и заканчиваются на одну и ту же букву: " << count;
    return 0;
}