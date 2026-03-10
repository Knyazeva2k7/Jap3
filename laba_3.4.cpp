#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "ДЕМОНСТРАЦИЯ РАБОТЫ СУММАТОРОВ" << endl;
    int N = 5; 

    cout << "РАННЕЕ СВЯЗЫВАНИЕ " << endl;
    //cout << "(тип объектов известен на этапе компиляции)" << endl;

    Summator simple;           // Обычный сумматор
    SquareSummator square;     // Квадратичный сумматор
    CubeSummator cube;         // Кубический сумматор


    cout << "\n1. Обычный сумматор (1+2+...+N):" << endl;
    cout << "   sum(" << N << ") = " << simple.sum(N) << endl;

    cout << "\n2. Квадратичный сумматор (1^2+2^2+...+N^2):" << endl;
    cout << "   sum(" << N << ") = " << square.sum(N) << endl;

    cout << "\n3. Кубический сумматор (1^3+2^3+...+N^3):" << endl;
    cout << "   sum(" << N << ") = " << cube.sum(N) << endl;

    // Показываем, как преобразуются элементы
    cout << "Демонстрация transform()" << endl;
    cout << "i\tОбычный\tКвадрат\tКуб" << endl;

    for (int i = 1; i <= N; i++) {
        cout << i << "\t" << simple.transform(i) << "\t"
            << square.transform(i) << "\t" << cube.transform(i) << endl;
    }

    cout << "ПОЗДНЕЕ СВЯЗЫВАНИЕ" << endl;
    //cout << "(тип объектов определяется во время выполнения)" << endl;

    Summator* ptr1 = new Summator();        // Указывает на обычный сумматор
    Summator* ptr2 = new SquareSummator();  // Указывает на квадратичный сумматор
    Summator* ptr3 = new CubeSummator();    // Указывает на кубический сумматор

    cout << "\nВызов transform() через указатели на базовый класс:" << endl;
    cout << "i\tptr1\tptr2\tptr3" << endl;

    for (int i = 1; i <= N; i++) {
        cout << i << "\t" << ptr1->transform(i) << "\t"
            << ptr2->transform(i) << "\t" << ptr3->transform(i) << endl;
    }

    // Вычисляем суммы через указатели
    cout << "\nВычисление сумм через указатели:" << endl;
    cout << "ptr1->sum(" << N << ") = " << ptr1->sum(N) << " (обычный)" << endl;
    cout << "ptr2->sum(" << N << ") = " << ptr2->sum(N) << " (квадраты)" << endl;
    cout << "ptr3->sum(" << N << ") = " << ptr3->sum(N) << " (кубы)" << endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;

    cout << "ПРОВЕРКА ПО ФОРМУЛАМ" << endl;

    N = 10;

    Summator s;
    SquareSummator sq;
    CubeSummator cb;

    // N(N+1)/2
    long long formula1 = N * (N + 1) / 2;
    cout << "\n1+2+...+10 = " << s.sum(N) << " (формула: " << formula1 << ")";
    if (s.sum(N) == formula1) 
        cout << " верно" << endl;

    // N(N+1)(2N+1)/6
    long long formula2 = N * (N + 1) * (2 * N + 1) / 6;
    cout << "1^2+2^2+...+10^2 = " << sq.sum(N) << " (формула: " << formula2 << ")";
    if (sq.sum(N) == formula2)
        cout << " верно" << endl;

    // [N(N+1)/2]^2
    long long formula3 = N * (N + 1) / 2;
    formula3 = formula3 * formula3;
    cout << "1^3+2^3+...+10^3 = " << cb.sum(N) << " (формула: " << formula3 << ")";
    if (cb.sum(N) == formula3) 
        cout << " верно" << endl;



    return 0;
}