#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BookInfo{
    string title;
    string author;
};

class Book {
    private:
        vector <BookInfo> BookList; 
    public:
        void addbook();
        void displaybooks();
        void pickbook();
        void returnbook();
        void totalbooks() const;
};

void Book::addbook() {
    cin.ignore();
    BookInfo newBook;
    cout << "Enter Title of Book: ";
    getline(cin, newBook.title);
    cout << "Enter Author of Book: ";
    getline(cin, newBook.author);
    BookList.push_back(newBook);
    cout << "Book added successfully!\n";
}

void Book::displaybooks() {
    if (BookList.empty()) {
        cout << "\nNo books available in the library.\n";
        return;
    }

    cout << "\n--- List of Books ---\n";
    for (size_t i = 0; i < BookList.size(); ++i) {
        cout << i + 1 << ". Title: " << BookList[i].title
             << " | Author: " << BookList[i].author << endl;
    }
}

void Book::pickbook() {
    if (BookList.empty()) {
        cout << "No books available to pick.\n";
        return;
    }
    int idx;
    cout << "Enter the number of the book to pick: ";
    cin >> idx;
    if (idx < 1 || idx > (int)BookList.size()) {
        cout << "Invalid book number.\n";
        return;
    }
    cout << "You picked: " << BookList[idx-1].title << " by " << BookList[idx-1].author << endl;
    BookList.erase(BookList.begin() + (idx-1));
}

void Book::returnbook() {
    cin.ignore();
    BookInfo returnedBook;
    cout << "Enter Title of Book to return: ";
    getline(cin, returnedBook.title);
    cout << "Enter Author of Book to return: ";
    getline(cin, returnedBook.author);
    BookList.push_back(returnedBook);
    cout << "Book returned successfully!\n";
}

void Book::totalbooks() const {
    cout << "Total books in library: " << BookList.size() << endl;
}

int main() {
    Book library;
    int choice;

    do {
        cout << "\nWelcome!\n"
             << "1. Add Book\n"
             << "2. Display Books\n"
             << "3. Pick Book\n"
             << "4. Return Book\n"
             << "5. Total Books\n"
             << "6. Exit\n"
             << "Select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addbook();
                break;
            case 2:
                library.displaybooks();
                break;
            case 3:
                library.pickbook();
                break;
            case 4:
                library.returnbook();
                break;
            case 5:
                library.totalbooks();
                break;
            case 6:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    } while (choice != 6);
    return 0;
}
