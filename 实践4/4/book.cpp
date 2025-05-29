#include "book.h"
#include <iostream>

using namespace std;
/*
class Book {
private:
    std::string ISBN;
    std::string title;
    std::string author;
    CDate copyrightDate;
    bool isAvailable;

    bool isValidISBN(const std::string &isbn) const;

public:
    Book(const std::string &isbn = "000-000-000-0", 
         const std::string &title = "Untitled", 
         const std::string &author = "NoNamae", 
         const CDate &date = CDate(), 
         bool available = true);

    // Getters
    std::string getISBN() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    CDate getCopyrightDate() const;
    bool getStatus() const;

    // Setters
    bool setISBN(const std::string &isbn);
    void setTitle(const std::string &title);
    void setAuthor(const std::string &author);
    void setCopyrightDate(const CDate &date);
    void setStatus(bool available);

    // Operations
    void printInfo() const;
    bool borrow();
    bool returnBook();
};*/

bool Book::isValidISBN(const string &isbn) const {
    regex pattern(R"(^\d+-\d+-\d+-[A-Za-z0-9]$)");//还得是正则表达式
    return regex_match(isbn, pattern);
}

Book::Book(const string &isbn, const string &title, 
           const string &author, const CDate &date, bool available)
    : title(title), author(author), copyrightDate(date), isAvailable(available) {
    setISBN(isbn);
}

string Book::getISBN() const { return ISBN; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
CDate Book::getCopyrightDate() const { return copyrightDate; }
bool Book::getStatus() const { return isAvailable; }

bool Book::setISBN(const string &isbn) {
    if (isValidISBN(isbn)) {
        ISBN = isbn;
        return true;
    }
    return false;
}

void Book::setTitle(const string &title) { this->title = title; }
void Book::setAuthor(const string &author) { this->author = author; }
void Book::setCopyrightDate(const CDate &date) { copyrightDate = date; }
void Book::setStatus(bool available) { isAvailable = available; }

void Book::printInfo() const {
    cout << "ISBN: " << ISBN << endl
         << "Title: " << title << endl
         << "Author: " << author << endl
         << "Copyright Date: ";
    copyrightDate.print();
    cout << endl << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
}

bool Book::borrow() {
    if (isAvailable) {
        isAvailable = false;
        return true;
    }
    return false;
}

bool Book::returnBook() {
    if (!isAvailable) {
        isAvailable = true;
        return true;
    }
    return false;
}