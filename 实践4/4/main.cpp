#include "book.h"
#include "date.h"
#include <iostream>

int main() {
    // 创建CDate对象
    CDate pubDate(2020, 12, 31, 0, 0, 0);
    
    // 创建并初始化Book对象
    Book book1("978-7-04-049592-6", "C++ Programming", "Bjarne Stroustrup", pubDate);//最近借的一本c++之父学写的书
    
    // 测试基本信息获取
    std::cout << "Book Info:" << std::endl;
    book1.printInfo();
    std::cout << std::endl;
    
    // 测试借阅功能
    if (book1.borrow()) {
        std::cout << "Book borrowed successfully!" << std::endl;
    } else {
        std::cout << "Book is not available for borrowing!" << std::endl;
    }
    book1.printInfo();
    std::cout << std::endl;
    
    // 测试归还功能
    if (book1.returnBook()) {
        std::cout << "Book returned successfully!" << std::endl;
    } else {
        std::cout << "Book was not borrowed!" << std::endl;
    }
    book1.printInfo();
    
    return 0;
}//终于写完啦嘎嘎嘎