#ifndef _BOOK_H
#define _BOOK_H

#include "date.h"
#include <string>
#include <regex>

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
         const std::string &author = "NoNamae", //欸嘿
         const CDate &date = CDate(), 
         bool available = true);

    // 查,都可以查
    std::string getISBN() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    CDate getCopyrightDate() const;
    bool getStatus() const;

    // 改,都可以该
    bool setISBN(const std::string &isbn);
    void setTitle(const std::string &title);
    void setAuthor(const std::string &author);
    void setCopyrightDate(const CDate &date);
    void setStatus(bool available);

    // 借,都可以借
    void printInfo() const;
    bool borrow();
    bool returnBook();
};

#endif // BOOK_H