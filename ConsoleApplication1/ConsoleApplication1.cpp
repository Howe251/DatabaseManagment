#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(clock());
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* values = new int[size];

    for (int i = 0; i < size; i++) {
        values[i] = rand();
    }
    cout << "Исходный массив:" << "\n";
    for (int i = 0; i < size; i++) {
        cout << i+1 << ": " << values[i] << "\n";
    }
    //Сортировка
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
    cout << "Отсортированный массив:" << "\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": " << values[i] << "\n";
    }
}
