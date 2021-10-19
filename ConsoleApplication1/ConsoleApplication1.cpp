#include <iostream>
#include <cstdlib>

using namespace std;

/*!
Функция сортировки массива
Принимает на вход размер массива и сам массив
*/
int sort(int size, int values[]) {
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
int massSet(int size, int values[]) {
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
int printMass(int size, int values[]) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": " << values[i] << "\n";
    }
    return 0;
}

/*
Главная функция
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* values = new int[size];
    massSet(size, values);      // Заполнение массива
    cout << "Исходный массив:" << "\n";
    printMass(size, values);    // Вывод исходного массива
    sort(size, values);         // Сортировка
    cout << "Отсортированный массив:" << "\n";
    printMass(size, values);    // Вывод отсортированного массива
}
