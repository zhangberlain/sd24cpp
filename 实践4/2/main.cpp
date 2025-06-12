#include "rational.h"
#include <iostream>
#include <stdexcept>

void test_constructors() {
    std::cout << "===== Testing Constructors =====" << std::endl;
    Rational r1; // Ĭ�Ϲ��캯��
    Rational r2(5); // int ���캯��
    Rational r3(3.14); // double ���캯��
    
    std::cout << "r1 (default): " << r1.get_int() << " / " << r1.get_double() << std::endl;
    std::cout << "r2 (int 5): " << r2.get_int() << " / " << r2.get_double() << std::endl;
    std::cout << "r3 (double 3.14): " << r3.get_int() << " / " << r3.get_double() << std::endl;
}

void test_arithmetic_operations() {
    std::cout << "\n===== Testing Arithmetic Operations =====" << std::endl;
    Rational a(4), b(2), c(1.5);
    
    // �ӷ�
    std::cout << "4 + 2 = " << (a + b).get_int() << std::endl;
    std::cout << "4 + 1.5 = " << (a + c).get_double() << std::endl;
    
    // ����
    std::cout << "4 - 2 = " << (a - b).get_int() << std::endl;
    std::cout << "4 - 1.5 = " << (a - c).get_double() << std::endl;
    
    // �˷�
    std::cout << "4 * 2 = " << (a * b).get_int() << std::endl;
    std::cout << "4 * 1.5 = " << (a * c).get_double() << std::endl;
    
    // ����
    std::cout << "4 / 2 = " << (a / b).get_int() << std::endl;
    std::cout << "4 / 1.5 = " << (a / c).get_double() << std::endl;
    
    // ���Գ����쳣
    try {
        Rational zero(0);
        std::cout << "4 / 0 = ";
        std::cout << (a / zero).get_int() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void test_fraction_operations() {
    std::cout << "\n===== Testing Fraction Operations =====" << std::endl;
    Rational a(6), b(4);
    
    // ������ʾ
    std::cout << "6/4 as fraction: " << a.div_fenshu(b) << std::endl;
    std::cout << "6/4 simplified: " << a.div_fenshu(4) << std::endl;
    
    // ���Է������쳣
    try {
        Rational c(1.5);
        std::cout << "1.5/4 as fraction: " << c.div_fenshu(b) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void test_mixed_operations() {
    std::cout << "\n===== Testing Mixed Operations =====" << std::endl;
    Rational a(3), b(1.5);
    
    // �����������
    std::cout << "3 + 1.5 = " << (a + 1.5).get_double() << std::endl;
    std::cout << "3 - 1.5 = " << (a - 1.5).get_double() << std::endl;
    std::cout << "3 * 1.5 = " << (a * 1.5).get_double() << std::endl;
    std::cout << "3 / 1.5 = " << (a / 1.5).get_double() << std::endl;
}

int main(int argc, char** argv) {
    test_constructors();
    test_arithmetic_operations();
    test_fraction_operations();
    test_mixed_operations();
    
    return 0;
}