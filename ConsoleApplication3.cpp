#include <iostream>
#include <windows.h>
#include <locale.h>


using namespace std;

struct Pair {
    float first, second;
    Pair(float f = 0, float s = 0) { // конструктор с параметрами по умолчанию
        first = f;
        second = s;
    }
    void operator+=(const Pair& p) { // перегрузка операции +=
        first += p.first;
        second += p.second;
    }
    friend bool operator==(const Pair& p1, const Pair& p2); // дружественная функция сравнения
    friend void display(const Pair& p); // дружественная функция вывода
};

bool operator==(const Pair& p1, const Pair& p2) { // реализация операции сравнения
    if (p1.first == p2.first && p1.second == p2.second)
        return true;
    else
        return false;
}

void display(const Pair& p) { // реализация функции вывода
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    Pair p1(3.5, 4.2), p2(1.2, 5.7), p3;
    p3 = p1;
    p3 += p2; // применение операции +=
    display(p1);
    display(p2);
    display(p3);
    if (p1 == p2)
        cout << "p1 и p2 равны" << endl;
    else
        cout << "p1 и p2 не равны" << endl;
    return 0;
}