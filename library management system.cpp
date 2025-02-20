#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;  // Maximum number of books in the library

// Class to represent a Book
class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book() : title(""), author(""), isAvailable(true) {}  // Default constructor
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}
};

// Class to represent a Library
class Library {
private:
    Book books[MAX_BOOKS];  // Fixed-size array of books
    int bookCount;          // Keeps track of the number of books

public:
    Library() : bookCount(0) {}  // Initialize book count to 0

    // Function to add a new book to the library
    void addBook(const string& title, const string& author) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = Book(title, author);
            cout << "Book added: " << title << " by " << author << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    // Function to display all available books
    void displayBooks() {
        cout << "\nAvailable Books:\n";
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].isAvailable) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books available." << endl;
        }
    }

    // Function to check out a book
    void checkOutBook(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title && books[i].isAvailable) {
                books[i].isAvailable = false;
                cout << "You have checked out: " << title << endl;
                return;
            }
        }
        cout << "Book not available for checkout: " << title << endl;
    }

    // Function to return a book
    void returnBook(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title && !books[i].isAvailable) {
                books[i].isAvailable = true;
                cout << "You have returned: " << title << endl;
                return;
            }
        }
        cout << "This book was not checked out: " << title << endl;
    }
};

// Main function to demonstrate the Library Management System
int main() {
    Library library;

    // Adding books to the library
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("1984", "George Orwell");
    library.addBook("To Kill a Mockingbird", "Harper Lee");

    // Display available books
    library.displayBooks();

    // Check out a book
    library.checkOutBook("1984");
    library.displayBooks();

    // Return a book
    library.returnBook("1984");
    library.displayBooks();

    // Attempt to check out a book that is not available
    library.checkOutBook("The Great Gatsby");
    library.checkOutBook("The Great Gatsby"); // Check out again

    // Return a book that was not checked out
    library.returnBook("The Great Gatsby");

    return 0;
}

