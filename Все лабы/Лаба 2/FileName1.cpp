#include <iostream>
#include <string>
using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Введите название публикации: ";
        getline(cin, title);
        cout << "Введите цену публикации: ";
        cin >> price;
        cin.ignore(); // очистка буфера
    }

    void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

// Класс Book (наследуется от Publication)
class Book : public Publication {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
};

// Класс Type (наследуется от Publication)
class Type : public Publication {
private:
    float play_time; // время записи в минутах

public:
    void getdata() {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> play_time;
        cin.ignore();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Время записи: " << play_time << " мин." << endl;
    }
};

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите данные для книги:\n";
    Book b;
    b.getdata();

    cout << "\nИнформация о книге:\n";
    b.putdata();

    cout << "\nВведите данные для аудиозаписи:\n";
    Type t;
    t.getdata();

    cout << "\nИнформация об аудиозаписи:\n";
    t.putdata();

    return 0;
}
