#include <iostream>
#include <vector>
#include <memory>   // shared_ptr
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <sstream>  // ostringstream

using namespace std;

// ======= Базовый класс Base =======
class Base {
protected:
    string name;

    // protected-конструктор — создание напрямую запрещено
    Base(const string& n) : name(n) {}

public:
    virtual ~Base() {}

    // Виртуальная функция — может быть переопределена в потомках
    virtual void show() const {
        cout << "Объект класса Base: " << name << endl;
    }

    // Делаем фабрику другом, чтобы она могла вызвать protected-конструктор
    friend shared_ptr<Base> createBase(const string& n);
}; // <-- точка с запятой обязательна

// ======= Производный класс Derived =======
class Derived : public Base {
protected:
    int value;

    // protected-конструктор
    Derived(const string& n, int v) : Base(n), value(v) {}

public:
    void show() const override {
        cout << "Объект класса Derived: " << name
            << ", значение: " << value << endl;
    }

    // Делаем фабрику другом
    friend shared_ptr<Derived> createDerived(const string& n, int v);
}; // <-- точка с запятой

// ======= Определения фабрик =======
shared_ptr<Base> createBase(const string& n) {
    return shared_ptr<Base>(new Base(n));
}

shared_ptr<Derived> createDerived(const string& n, int v) {
    return shared_ptr<Derived>(new Derived(n, v));
}

// ======= Главная функция =======
int main() {
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned>(time(0)));

    vector<shared_ptr<Base>> storage;

    // Создаём 5 случайных объектов и добавляем в вектор
    for (int i = 0; i < 5; ++i) {
        int randomNum = rand() % 2;

        ostringstream oss;
        oss << i;
        string idx = oss.str();

        if (randomNum == 0) {
            string name = "База_" + idx;
            storage.push_back(createBase(name));
        }
        else {
            string name = "Потомок_" + idx;
            int val = rand() % 100;
            storage.push_back(createDerived(name, val));
        }
    }

    // Выводим все объекты (полиморфный вызов show)
    cout << "\nСодержимое хранилища:\n";
    for (size_t i = 0; i < storage.size(); ++i) {
        storage[i]->show();
    }

    cout << "\nВсе ресурсы будут автоматически освобождены.\n";
    return 0;
}   
