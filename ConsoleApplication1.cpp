#include <iostream>
#include <cmath>
#include <locale.h>
#include <windows.h>


using namespace std;

class Power {
private:
    double first, second;
public:
    Power(double f = 0, double s = 0) { // конструктор с параметрами
        first = f;
        second = s;
    }
    double power() { // метод возведения числа в степень
        return pow(first, second);
    }
};

Power make_Power(double f, double s) { // функция создания объекта класса Power
    if (f == 0 && s == 0) {
        cout << "Ошибка: переданы нулевые значения\n";
        exit(0); // принудительное завершение программы 
    }
    else {
        Power p(f, s);
        return p;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    double f, s;
    cout << "Введите дробное число: ";
    cin >> f;
    cout << "Введите показатель степени: ";
    cin >> s;
    Power obj = make_Power(f, s); // создание объекта класса Power
    cout << "Результат возведения числа " << f << " в степень " << s << " равен: " << obj.power() << endl; // вычисление и вывод результата
    return 0;
}
