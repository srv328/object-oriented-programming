#include <stdio.h>
#include <iostream>

using namespace std;
class PassengerShip // класс пассажирского судна
{
public:
  void info();
  PassengerShip(string valueN, double valueL, double valueW, int valuePC); 
private:
  string name; //название судна
  double length; //длина судна
  double width; //ширина судна
  int passengerCount; //количество пассажиров судна
};

PassengerShip::PassengerShip(string valueN, double valueL, double valueW, int valuePC) //конструктор класса PassengerShip
{
  name = valueN;
  length = valueL;
  width = valueW;
  passengerCount = valuePC;
}
void PassengerShip::info()
{
  cout << "Название судна: " << name << endl;
  cout << "Количество пассажиров судна: " << passengerCount << endl;
  cout << "Ширина судна:" << length << endl;
  cout << "Длина судна:" << width << endl;
  cout << endl;
}

int main()
{
  setLocale(LC_ALL, "Russian");
  PassengerShip YAMATO1("Ямато", 101.5, 201.5, 51);
  PassengerShip YAMATO2("Титаник",102.5, 202.5, 52);
  PassengerShip YAMATO3("Наутилус", 103.5, 203.5, 53);
  PassengerShip YAMATO4("ЯлтаПарус", 104.5, 204.5, 54);
  PassengerShip YAMATO5("AVIZOHELLA", 105.5, 205.5, 55);
  YAMATO1.info();
  YAMATO2.info();
  YAMATO3.info();
  YAMATO4.info();
  YAMATO5.info();
}