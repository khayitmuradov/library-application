#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string subtitle;
    string author;
    int year;
    double price;

public:
    Book(string title, string subtitle, string author, int year, double price)
        : title(title), subtitle(subtitle), author(author), year(year), price(price) {}

    string getTitle() const { return title; }
    string getSubtitle() const { return subtitle; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    bool operator==(const Book& other) const {
        return title == other.title &&
            subtitle == other.subtitle &&
            author == other.author &&
            year == other.year &&
            price == other.price;
    }
};

class Library {
private:
    string name;
    string openHours;
    vector<Book> books;

public:
    Library(string name, string openHours) : name(name), openHours(openHours) {}

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void deleteBook(const Book& book) {
        auto it = find(books.begin(), books.end(), book);
        if (it != books.end()) {
            books.erase(it);
            cout << "\nBook deleted successfully.\n\n" << endl;
        }
        else {
            cout << "\nBook not found in the library.\n\n" << endl;
        }
    }

    bool findBook(const Book& book) const {
        return find(books.begin(), books.end(), book) != books.end();
    }

    vector<Book> getAllBooks() const {
        return books;
    }

    void saveLibraryToFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& book : books) {
                outFile << book.getTitle() << "," 
                    << book.getSubtitle() << "," 
                    << book.getAuthor() << "," 
                    << book.getYear() << "," 
                    << book.getPrice() << endl;
            }
            outFile.close();
            cout << "\nLibrary data saved to file successfully.\n\n" << endl;
        }
        else {
            cout << "\nUnable to open file to save library data.\n\n" << endl;
        }
    }
};

int main() {
    Library library("Alisher Navoiy", "9:00 AM - 8:00 PM");

    int choice;
    do {
        cout << "1. Add Book" << endl;
        cout << "2. Delete Book" << endl;
        cout << "3. Find Book" << endl;
        cout << "4. View All Books" << endl;
        cout << "5. Save Library Data" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string title, subtitle, author;
            int year;
            double price;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter subtitle: ";
            getline(cin, subtitle);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter price: ";
            cin >> price;
            Book newBook(title, subtitle, author, year, price);
            library.addBook(newBook);
            break;
        }
        case 2: {
            string title, subtitle, author;
            int year;
            double price;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter subtitle: ";
            getline(cin, subtitle);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter price: ";
            cin >> price;
            Book bookToDelete(title, subtitle, author, year, price);
            library.deleteBook(bookToDelete);
            break;
        }
        case 3: {
            string title, subtitle, author;
            int year;
            double price;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter subtitle: ";
            getline(cin, subtitle);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter price: ";
            cin >> price;
            Book bookToFind(title, subtitle, author, year, price);
            if (library.findBook(bookToFind)) {
                cout << "\nBook found in the library.\n\n" << endl;
            }
            else {
                cout << "\nBook not found in the library.\n\n" << endl;
            }
            break;
        }
        case 4: {
            cout << "\nAll Books in the Library:\n" << endl;
            vector<Book> allBooks = library.getAllBooks();
            for (const auto& book : allBooks) {
                cout << "Title: " << book.getTitle() << 
                    ", Subtitle: " << book.getSubtitle() << 
                    ", Author: " << book.getAuthor() << 
                    ", Year: " << book.getYear() << 
                    ", Price: " << book.getPrice() << endl << endl;
            }
            break;
        }
        case 5:
            library.saveLibraryToFile("library_data.txt");
            break;
        case 6:
            cout << "\nExiting..." << endl;
            break;
        default:
            cout << "\nInvalid choice! Please enter a valid option.\n" << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}