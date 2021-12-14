#include <iostream>
#include <cstdlib>
#include "../API/DEQ.h"

using namespace std;
/*!
Функция сортировки массива
Принимает на вход размер массива и указатель на массив
*/
int sort(const int size, int *values);
/*!
Функция заполнения массива радомными значениями
Принимает на вход размер массива и указатель на массив
*/
int massSet(const int size, int *values);
/*!
Функция вывода массива на экран
Принимает на вход размер массива и указатель на массив
*/
int printMass(const int size, int *values);
/*!
Функция установки размера массива
*/
int setSize();

/*
Главная функция
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "1. Работа с массивом\n2. Работа с ДЭК\nВыбор:";
    int work;
    cin >> work;
    if (work == 1) {
        setlocale(LC_ALL, "Russian");
        const int size = setSize();
        int* values = new int[size];
        massSet(size, values);      // Заполнение массива
        cout << "Исходный массив:" << "\n";
        printMass(size, values);    // Вывод исходного массива
        sort(size, values);         // Сортировка
        cout << "Отсортированный массив:" << "\n";
        printMass(size, values);    // Вывод отсортированного массива
        cin.get();
        return 0;
    }
    else if (work == 2) {
        DEQ deque = {1,2,3,4};
        cout << "ASD";
        //deque.PopFront();
        deque.PushFront(2);
        cout << deque.PopFront();
    }   
}


int setSize() {
    int size;
    cout << "Введите размер массива: ";
    while (true)    // Проверка на положительный размер массива
    {
        cin >> size;
        if (size < 0)
        {
            cout << "Введите положительное число элементов: ";
        }
        else return size;
    }
}


int sort(const int  size, int *values) {
    for (int stInd = 0; stInd < size - 1; stInd++)
    {
        int maxIndex = stInd;
        for (int curInd = stInd + 1; curInd < size; curInd++)
        {
            if (values[curInd] > values[maxIndex])
                maxIndex = curInd;
        }
        swap(values[stInd], values[maxIndex]);
    }
    return 0;
}


int massSet(const int  size, int *values) {
    srand(clock());
    for (int i = 0; i < size; i++) {
        values[i] = rand();
    }
    return 0;
}


int printMass(const int  size, int *values) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": " << values[i] << "\n";
    }
    return 0;
}

