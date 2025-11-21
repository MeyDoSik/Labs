#include <iostream>
#include <string>
#include <stdexcept>  // для стандартных исключений
using namespace std;

// ===== Базовый класс ошибки =====
class Error {
protected:
    string message;
public:
    Error(string msg) : message(msg) {}
    virtual void show() const {
        cout << "Ошибка: " << message << endl;
    }
    virtual ~Error() {}
};

// ===== Производные классы =====
class MemoryAccessError : public Error {
public:
    MemoryAccessError() : Error("Ошибка доступа к памяти") {}
};

class MathError : public Error {
public:
    MathError() : Error("Математическая ошибка") {}
};

class DivideByZeroError : public MathError {
public:
    DivideByZeroError() { message = "Деление на ноль"; }
};

class OverflowError : public MathError {
public:
    OverflowError() { message = "Переполнение"; }
};

// ===== Шаблонный класс хранения указателей =====
template <typename T>
class Storage {
private:
    T** arr;      // массив указателей
    int size;     // размер массива
public:
    // Конструктор
    Storage(int s) {
        if (s <= 0)
            throw invalid_argument("Размер массива должен быть положительным");
        size = s;
        arr = new T * [size];
        for (int i = 0; i < size; i++) arr[i] = nullptr;
    }

    // Перегрузка оператора []
    T*& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Выход за пределы массива Storage");
        return arr[index];
    }

    // Метод для получения размера
    int getSize() const { return size; }

    // Деструктор
    ~Storage() {
        for (int i = 0; i < size; i++)
            delete arr[i]; // освобождаем память под объекты
        delete[] arr;
    }
};

// ===== Главная функция =====
int main() {
    setlocale(LC_ALL, "Russian");

    try {
        cout << "Создание хранилища ошибок...\n";
        Storage<Error> errors(4);

        // Заполняем хранилище объектами разных типов
        errors[0] = new MemoryAccessError();
        errors[1] = new MathError();
        errors[2] = new DivideByZeroError();
        errors[3] = new OverflowError();

        cout << "\nВывод сообщений об ошибках:\n";
        for (int i = 0; i < errors.getSize(); i++)
            errors[i]->show();

        cout << "\nПопробуем выйти за пределы массива:\n";
        errors[10] = new OverflowError(); // вызовет исключение

    }
    catch (const out_of_range& e) {
        cerr << "Исключение: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Неверный аргумент: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Неизвестная ошибка!" << endl;
    }

    cout << "\nПрограмма завершена без утечек памяти.\n";
    return 0;
}


