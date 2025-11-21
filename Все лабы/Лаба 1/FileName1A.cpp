#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n]; // динамический массив

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

    delete[] arr; // освобождение памяти
    return 0;
}
