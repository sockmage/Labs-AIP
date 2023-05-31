#include <iostream>
#include <cmath>
#include <windows.h>
#include <locale.h>


using namespace std;

class Double {
private:
    double num;
public:
    Double(double n = 0) { // конструктор с параметрами
        num = n;
    }
    void read() { // метод для ввода значения
        cout << "Введите значение: ";
        cin >> num;
    }
    void display() { // метод для вывода значения
        cout << "Значение: " << num << endl;
    }
    Double operator+(Double d) { // перегрузка оператора сложения
        Double temp;
        temp.num = num + d.num;
        return temp;
    }
    Double operator-(Double d) { // перегрузка оператора вычитания
        Double temp;
        temp.num = num - d.num;
        return temp;
    }
    Double power(int n) { // метод для возведения в степень
        Double temp;
        temp.num = pow(num, n);
        return temp;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    Double d1, d2;
    d1.read();
    d2.read();
    Double add = d1 + d2; // сложение
    Double sub = d1 - d2; // вычитание
    int n;
    cout << "Введите степень: ";
    cin >> n;
    Double pow = d1.power(n); // возведение в степень
    d1.display();
    d2.display();
    add.display();
    sub.display();
    pow.display();
    return 0;
}