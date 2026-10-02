#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    float price;
    static int bookCount;

public:
    // Parameterized Constructor with default arguments
    Book(int id = 0, string t = "Unknown", string a = "Unknown", float p = 0.0) {
        bookId = id;
        title = t;
        author = a;
        price = p;
        bookCount++;
        cout << "Book created. Total books: " << bookCount << endl;
    }

    // Copy Constructor
    Book(const Book &b) {
        bookId = b.bookId;
        title = b.title;
        author = b.author;
        price = b.price;
        bookCount++;
        cout << "Book copied. Total books: " << bookCount << endl;
    }

    // Destructor
    ~Book() {
        bookCount--;
        cout << "Book destroyed. Total books: " << bookCount << endl;
    }

    // Display function
    void display() const {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    // Static member function to get the current book count
    static int getBookCount() {
        return bookCount;
    }
};

// Initialize static member variable
int Book::bookCount = 0;

int main() {
    // Creating an object using the parameterized constructor
    Book b1(101, "C++ Programming", "Bjarne Stroustrup", 4500);
    b1.display();

    cout << "\n--- Demonstrating Copy Constructor ---" << endl;
    Book b2 = b1; 
    b2.display();

    cout << "Total books: " << Book::getBookCount() << endl;
    return 0;
}