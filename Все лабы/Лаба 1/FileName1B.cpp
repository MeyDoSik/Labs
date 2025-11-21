#include <iostream>
using namespace std;

int main() {
    int n = 10;
    double* arr = new double[n];

    // Заполнение массива
    for (int i = 0; i < n; ++i) {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Вывод массива и адресов
    cout << "\nСодержимое массива:\n";
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = " << arr[i]
            << ", адрес: " << &arr[i]
            << ", смещение от начала: "
            << (char*)(&arr[i]) - (char*)arr
            << " байт\n";
    }

    cout << "Адрес начала массива: " << arr << endl;

    delete[] arr;
    return 0;
}
