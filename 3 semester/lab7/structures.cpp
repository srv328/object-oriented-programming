#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

struct ZNAK {
    int BDAY[3];    // День рождения
    std::string NAME;    // Фамилия и Имя
    std::string ZODIAC;  // Знак Зодиака
};

string ReceiveAData() {
    string content;
    string line;
    getline(cin, line);
    content += line + '\n';
    return content;
}

int main() {
    setlocale(LC_ALL, "Russian");
    ZNAK BOOK[8];
    ZNAK q;
    for (int i = 0; i < 8; i++) {
        q = BOOK[i];
        cout << "Введите день рождения: ";
        cout << "\nДата: ";
        q.BDAY[0] = stoi(ReceiveAData());
        cout << "Месяц: ";
        q.BDAY[1] = stoi(ReceiveAData());
        cout << "Год: ";
        q.BDAY[2] = stoi(ReceiveAData());
        cout << "Введите знак зодиака: ";
        q.ZODIAC = ReceiveAData();
        cout << "Введите данные в формате Фамилия Имя: ";
        q.NAME = ReceiveAData();
        cout << endl;
        BOOK[i] = q;
    }
    cout << endl << endl << endl << endl;
    bool sort = true;
    ZNAK temp;
    while (sort) {
        sort = false;
        for (int i = 0; i < 7;i++) {
            if (BOOK[i].BDAY[2] > BOOK[i + 1].BDAY[2]) {
                temp = BOOK[i];
                BOOK[i] = BOOK[i + 1];
                BOOK[i + 1] = temp;
                sort = true;
            }
            if ((BOOK[i].BDAY[2] == BOOK[i + 1].BDAY[2]) && (BOOK[i].BDAY[1] > BOOK[i + 1].BDAY[1])){
                temp = BOOK[i];
                BOOK[i] = BOOK[i + 1];
                BOOK[i + 1] = temp;
                sort = true;
            }
            if ((BOOK[i].BDAY[2] == BOOK[i + 1].BDAY[2]) && (BOOK[i].BDAY[1] == BOOK[i + 1].BDAY[1]) && (BOOK[i].BDAY[0] > BOOK[i + 1].BDAY[0])) {
                temp = BOOK[i];
                BOOK[i] = BOOK[i + 1];
                BOOK[i + 1] = temp;
                sort = true;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        ZNAK q = BOOK[i];
        cout << "\n\n Сведения о человеке: ";
        cout << "\n День рождения: " << q.BDAY[0] << " " << q.BDAY[1] << " " << q.BDAY[2];
        cout << "\n Фамилия и имя: " << q.NAME;
        cout << " Знак зодиака: " << q.ZODIAC;
    }
    std::string zod;
    cout << "Введите знак зодиака, который необходимо найти: ";
    zod = ReceiveAData();;
    bool flag = false;
    for (int i = 0; i < 8; i++) {
        ZNAK q = BOOK[i];
        if (q.ZODIAC == zod) {
            cout << "\n\n Сведения о человеке: ";
            cout << "\n День рождения: " << q.BDAY[0] << " " << q.BDAY[1] << " " << q.BDAY[2];
            cout << "\n Фамилия и имя: " << q.NAME;
            cout << " Знак зодиака: " << q.ZODIAC;
            flag = true;
        }
    }
    if (!flag) {
        cout << "Людей с таким знаком зодиака не было найдено.";
    }
    return 0;
}