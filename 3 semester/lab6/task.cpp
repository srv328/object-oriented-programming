#include <iostream>
#include <cctype>
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;

void message() {

	cout << "\nУзнать количество слов, которые начинаются и заканчиваются на одну и ту же букву - нажмите 1";
	cout << "\nВыход - нажмите f";
}

int main(int argc, const char* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	char str[255];
	char switcher;
	cout << "Enter the string: ";
	gets_s(str);
	size = strlen(str);

	for (;;)
	{
		cout << endl << endl << "Ваша исходная строка: " << str;
		message();
		cout << "\nВаш выбор: ";
		cin >> switcher;
		switch (switcher)
		{
		case '1':
			int count = 0;
			stringstream strm(str);
			for (string i;strm >> i;)
				if (i[0] == i[i.length() - 1])
					count++;
			cout << "Количество слов, которые начинаются и заканчиваются на одну и ту же букву: " << count;
			break;
		}
		if (switcher == 'f')
			break;
	}

	system("pause");
	return 0;
}
