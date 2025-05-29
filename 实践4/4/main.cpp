#include "book.h"
#include "date.h"
#include <iostream>

int main() {
    // ����CDate����
    CDate pubDate(2020, 12, 31, 0, 0, 0);
    
    // ��������ʼ��Book����
    Book book1("978-7-04-049592-6", "C++ Programming", "Bjarne Stroustrup", pubDate);//������һ��c++֮��ѧд����
    
    // ���Ի�����Ϣ��ȡ
    std::cout << "Book Info:" << std::endl;
    book1.printInfo();
    std::cout << std::endl;
    
    // ���Խ��Ĺ���
    if (book1.borrow()) {
        std::cout << "Book borrowed successfully!" << std::endl;
    } else {
        std::cout << "Book is not available for borrowing!" << std::endl;
    }
    book1.printInfo();
    std::cout << std::endl;
    
    // ���Թ黹����
    if (book1.returnBook()) {
        std::cout << "Book returned successfully!" << std::endl;
    } else {
        std::cout << "Book was not borrowed!" << std::endl;
    }
    book1.printInfo();
    
    return 0;
}//����д�����¸¸�