

#include <iostream>
#include<windows.h>
#include<string>
using namespace std;


struct book
{
	string name;
	string author;
	string publisher;
	string genre;
};
void printbook(book b, int number) {
	cout << "Книга №" << number + 1 << endl;
	cout << "Назва: " << b.name << endl;
	cout << "Автор: " << b.author << endl;
	cout << "Видавництво: " << b.publisher << endl;
	cout << "Жанр: " << b.genre << endl;
	cout << "-----------------------------" << endl;
}

void editBook(book books[], int size) {
    int number;

    cout << "Введіть номер книги для редагування (1-10): ";
    cin >> number;
    cin.ignore();

    if (number < 1 || number > size) {
        cout << "Неправильний номер!"<<endl;
        return;
    }

    number--;

    cout << "Нова назва: ";
    getline(cin, books[number].name);

    cout << "Новий автор: ";
    getline(cin, books[number].author);

    cout << "Нове видавництво: ";
    getline(cin, books[number].publisher);

    cout << "Новий жанр: ";
    getline(cin, books[number].genre);

    cout << "Книгу успішно відредаговано!"<<endl;
}


void printAll(book books[], int size) {
    cout << "\n========== ВСІ КНИГИ =========="<<endl;

    for (int i = 0; i < size; i++) {
        printbook(books[i], i);
    }
}
void searchAuthor(book books[], int size) {
    string author;
    bool found = false;

    cin.ignore();
    cout << "Введіть автора: ";
    getline(cin, author);

    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            printbook(books[i], i);
            found = true;
        }
    }

    if (!found) {
        cout << "Книг цього автора не знайдено.\n";
    }
}

void searchName(book books[], int size) {
    string name;
    bool found = false;

    cin.ignore();
    cout << "Введіть назву книги: ";
    getline(cin, name);

    for (int i = 0; i < size; i++) {
        if (books[i].name == name) {
            printbook(books[i], i);
            found = true;
        }
    }

    if (!found) {
        cout << "Книг цієї назви не знайдено.\n";
    }
}

void sortByName(book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].name > books[j + 1].name) {
                swap(books[j], books[j + 1]);
            }
        }
    }

    cout << "Книги відсортовано за назвою!\n";
}

void sortByAuthor(book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].author > books[j + 1].author) {
                swap(books[j], books[j + 1]);
            }
        }
    }

    cout << "Книги відсортовано за автором!\n";
}


void sortByPublisher(book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].publisher > books[j + 1].publisher) {
                swap(books[j], books[j + 1]);
            }
        }
    }

    cout << "Книги відсортовано за видавництвом!\n";
}


int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int SIZE = 10;
    book books[SIZE] = {
       {"Кобзар", "Тарас Шевченко", "Фоліо", "Поезія"},
       {"Захар Беркут", "Іван Франко", "А-БА-БА-ГА-ЛА-МА-ГА", "Історичний"},
       {"Кайдашева сім'я", "Іван Нечуй-Левицький", "Школа", "Повість"},
       {"Тигролови", "Іван Багряний", "КСД", "Пригоди"},
       {"Місто", "Валер'ян Підмогильний", "Фоліо", "Роман"},
       {"Чорна рада", "Пантелеймон Куліш", "Клуб Сімейного Дозвілля", "Історичний"},
       {"Лісова пісня", "Леся Українка", "Фоліо", "Драма"},
       {"Маруся Чурай", "Ліна Костенко", "А-БА-БА-ГА-ЛА-МА-ГА", "Роман у віршах"},
       {"Інтернат", "Сергій Жадан", "Meridian Czernowitz", "Роман"},
       {"Солодка Даруся", "Марія Матіос", "Піраміда", "Роман"}
    };

    int choice;

    do {
        cout << "\n========== БІБЛІОТЕКА =========="<<endl;
        cout << "1 - Редагувати книгу"<<endl;
        cout << "2 - Друк усіх книг"<<endl;
        cout << "3 - Пошук за автором"<<endl;
        cout << "4 - Пошук за назвою"<<endl;
        cout << "5 - Сортування за назвою"<<endl;
        cout << "6 - Сортування за автором"<<endl;
        cout << "7 - Сортування за видавництвом"<<endl;
        cout << "0 - Вихід"<<endl;
        cout << "================================"<<endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            editBook(books, SIZE);
            break;
		case 2:
            printAll(books, SIZE);
			break;

		case 3:
			searchAuthor(books, SIZE);
			break;
		case 4:
			searchName(books, SIZE);
			break;
		case 5:
			sortByName(books, SIZE);
			break;
		case 6:
			sortByAuthor(books, SIZE);
			break;
		case 7:
			sortByPublisher(books, SIZE);
			break;
		case 0:
			cout << "Вихід з програми." << endl;
			break;

        }
    } while (choice != 0);
    
}


