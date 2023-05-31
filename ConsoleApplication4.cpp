#include <iostream>
#include <windows.h>
#include <locale.h>


using namespace std;

class Point2D {
protected:
    float x, y;
public:
    Point2D(float _x = 0, float _y = 0) { // конструктор с параметрами
        x = _x;
        y = _y;
    }
    virtual void print() { // виртуальная функция для печати значений полей
        cout << "Точка на плоскости с координатами (" << x << ", " << y << ")" << endl;
    }
};

class Point3D : public Point2D {
private:
    float z;
public:
    Point3D(float _x = 0, float _y = 0, float _z = 0) : Point2D(_x, _y) { // конструктор с параметрами
        z = _z;
    }
    void print() { // переопределенная функция для печати значений полей
        Point2D::print(); // вызов функции из базового класса
        cout << "Точка в трехмерном пространстве с координатами (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    Point2D p2d(1.2, 3.4);
    Point3D p3d(5.6, 7.8, 9.0);
    Point2D* ptr; // указатель на объект базового класса
    ptr = &p2d; // указатель ссылается на объект базового класса
    ptr->print(); // вызов виртуальной функции из базового класса
    ptr = &p3d; // указатель ссылается на объект производного класса
    ptr->print(); // вызов переопределенной функции из производного класса с использованием динамического полиморфизма
    return 0;
}
