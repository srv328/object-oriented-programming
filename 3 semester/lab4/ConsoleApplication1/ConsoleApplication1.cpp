﻿#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct scan_info {
    string model; // наименование модели
    int price;  // цена
    double x_size;  // горизонтальный размер области сканирования
    double y_size; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
    int grey; // число градаций серого
};
scan_info scan;
int Menu();
void Create(long* n);
void View();
int vivod_structure(long *n);

int Menu() {
    setlocale(LC_ALL, "Russian");
    char ch = '\0';
    cout << "1 - Создание файла\n";
    cout << "2 - Просмотр файла\n";
    cout << "3 - Вывести информацию о сканере и записать её в структуру\n";
    cout << "4 - Выход из программы\n";
    ch = getchar();
    return atoi(&ch);
}
int main() {
    long n;
    while (1) {
        switch (Menu()) {
        case 1: Create(&n); break;
        case 2: View(); break;
        case 3: vivod_structure(&n); break;
        case 4: return 0;
        default: break;
        };
    };
}
void Create(long* n) {
    FILE* data;
    fopen_s(&data, "file.bin", "w+b");
    do {
        cout << endl << "Введите количество записей (1-10): ";
        cin >> *n;
    } while ((*n < 1) || (*n > 10));
    fwrite(n, 4, 1, data);
    for (int i = 1; i <= *n; i++) {
        cout << "Сканер #: " << i << endl;
        cout << "Модель: ";
        cin >> scan.model;
        cout << "Цена: ";
        cin >> scan.price;
        cout << "Горизонтальная размер области сканирования: ";
        cin >> scan.x_size;
        cout << "Вертикальный размер области сканирования: ";
        cin >> scan.y_size;
        cout << "Оптическое разрешение: ";
        cin >> scan.optr;
        cout << "Число градаций серого: ";
        cin >> scan.grey;
        cout << endl;
        fwrite(&scan, sizeof(scan), 1, data);
    };
    fclose(data);
    cout << "Файл  file.bin  успешно создан." << endl << endl;
    getchar();
    return;
}

void View() {
    FILE* data1;
    fopen_s(&data1, "file.bin", "rb");
    if (data1 == NULL) {
        cout << "Файл для чтения отсутствует, невозможно открыть" << endl << endl;
        getchar();
        return;
    };
    long n;
    fread(&n, 4, 1, data1);
    cout << endl << "Количество сканеров: " << n << endl << endl;
    scan_info* s = new scan_info[n];
    for (int g = 0; g < n; g++)
        fread(&s[g], sizeof(scan_info), 1, data1);
    scan_info** q = new scan_info * [n]; 
    for (int i = 0;i < n;i++) {
        q[i] = &s[i];
    }

    for (int g = 0; g < n; g++) {
        cout << "Сканер #: " << g + 1 << endl;
        cout << "Модель: " << q[g]->model << endl;
        cout << "Цена: " << q[g]->price << endl;
        cout << "Горизонтальный размер области сканирования: " << q[g]->x_size << endl;
        cout << "Вертикальный размер области сканирования: " << q[g]->y_size << endl;
        cout << "Оптическое разрешение: " << q[g]->optr << endl;
        cout << "Число градаций серого: " << q[g]->grey << endl;
        cout << endl;
    };
    fclose(data1);
    cout << endl << endl;
    getchar();
    return;
}

int vivod_structure(long *n) {
    scan_info new_struct;
    cout << "Введите номер сканера, информацию о котором нужно записать в структуру New_Struct: ";
    int col;
    FILE* data1;
    cin >> col;
    if (*n < col) {
        cout << "Такого количества сканеров нет в файле file.bin";
        cout << endl;
        return -1;
    }
    else {
        fopen_s(&data1, "file.bin", "rb");
        if (data1 == NULL) {
            cout << "Файл для чтения отсутствует, невозможно открыть" << endl << endl;
            getchar();
            return -1;
        };
        long n;
        fread(&n, 4, 1, data1);
        cout << endl << "Количество сканеров: " << n << endl << endl;
        scan_info* s = new scan_info[n];
        for (int g = 0; g < n; g++)
            fread(&s[g], sizeof(scan_info), 1, data1);
        scan_info** q = new scan_info * [n];
        for (int i = 0;i < n;i++) {
            q[i] = &s[i];
        }

        for (int g = 0; g < n; g++) {
            if (g+1 == col) {
                cout << "Сканер #: " << g + 1 << endl;
                cout << "Модель: " << q[g]->model << endl;
                cout << "Цена: " << q[g]->price << endl;
                cout << "Горизонтальный размер области сканирования: " << q[g]->x_size << endl;
                cout << "Вертикальный размер области сканирования: " << q[g]->y_size << endl;
                cout << "Оптическое разрешение: " << q[g]->optr << endl;
                cout << "Число градаций серого: " << q[g]->grey << endl;
                new_struct.model = q[g]->model;
                new_struct.price = q[g]->price;
                new_struct.x_size = q[g]->x_size;
                new_struct.y_size = q[g]->y_size;
                new_struct.optr = q[g]->optr;
                new_struct.grey = q[g]->grey;
                cout << endl;
                cout << "Запись в структуру new_struct была успешно завершена." << endl;
                return 0;
            }
        };
        fclose(data1);
        cout << endl << endl;
        cout << n;
        getchar();
    }
    return -1;
}
