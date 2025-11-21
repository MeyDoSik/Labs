#include <iostream>
#include <vector>
#include <string>
#include <locale>     // для русской локали
using namespace std;

class Book {
public:
    string author;
    string title;
    string type; // "fiction" или "technical"

    Book(string a, string t, string ty) {
        if (a.empty() || t.empty()) {
            throw invalid_argument("Автор и название книги не могут быть пустыми!");
        }
        author = a;
        title = t;
        type = ty;
    }
};

// Функция с использованием switch (имитация через if, так как switch не принимает string)
void countBooksSwitch(const vector<Book>& library) {
    int fiction = 0, technical = 0;

    for (const auto& book : library) {
        if (book.type == "fiction") {
            fiction++;
        }
        else if (book.type == "technical") {
            technical++;
        }
    }

    cout << "\n[С помощью switch]\n";
    cout << "Художественная литература: " << fiction << endl;
    cout << "Техническая литература: " << technical << endl;
}

// Функция без switch
void countBooksNoSwitch(const vector<Book>& library) {
    int fiction = 0, technical = 0;

    for (const auto& book : library) {
        if (book.type == "fiction")
            fiction++;
        else
            technical++;
    }

    cout << "\n[Без использования switch]\n";
    cout << "Художественная литература: " << fiction << endl;
    cout << "Техническая литература: " << technical << endl;
}

int main() {
    // Устанавливаем поддержку русской локали
    setlocale(LC_ALL, "ru_RU.UTF-8");

    vector<Book> library;

    try {
        library.push_back(Book("Иванов", "Моя книга", "fiction"));
        library.push_back(Book("Петров", "Техника будущего", "technical"));
        library.push_back(Book("Сидоров", "Приключения", "fiction"));
        library.push_back(Book("Кузнецов", "Программирование C++", "technical"));
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }

    countBooksSwitch(library);
    countBooksNoSwitch(library);

    return 0;
}
