#include <iostream>
#include <cstdlib>

using namespace std;
int sort(const int size, int *values);
int massSet(const int size, int *values);
int printMass(const int size, int *values);
int setSize(int *size);

/*
Главная функция
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    setSize(&size);             // Определить размер массива
    int* values = new int[size];
    massSet(size, values);      // Заполнение массива
    cout << "Исходный массив:" << "\n";
    printMass(size, values);    // Вывод исходного массива
    sort(size, values);         // Сортировка
    cout << "Отсортированный массив:" << "\n";
    printMass(size, values);    // Вывод отсортированного массива
}


/*!
Функция установки размера массива
Принимает на вход указательно на размер
*/
int setSize(int *size) {
    cout << "Введите размер массива: ";
    while (true)    // Проверка на положительный размер массива
    {
        cin >> *size;
        if (*size < 0)
        {
            cout << "Введите положительное число элементов: ";
        }
        else return *size;
    }
}

/*!
Функция сортировки массива
Принимает на вход размер массива и сам массив
*/
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

/*!
Функция заполнения массива радомными значениями
Принимает на вход размер массива и сам массив
*/
int massSet(const int  size, int *values) {
    srand(clock());
    for (int i = 0; i < size; i++) {
        values[i] = rand();
    }
    return 0;
}

/*!
Функция вывода массива на экран
Принимает на вход размер массива и сам массив
*/
int printMass(const int  size, int *values) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": " << values[i] << "\n";
    }
    return 0;
}

