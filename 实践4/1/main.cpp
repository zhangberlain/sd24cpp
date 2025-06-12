#include <iostream>
#include "complex.h"

using namespace std;
int main() {
    // 测试构造函数
    CComplex com1(1.1, 1.2);
    CComplex com2(3.0, 4.0);
    CComplex com3;

    // 测试 getReal() 和 getImg()
    cout << "com1: 实部 = " << com1.getReal() << ", 虚部 = " << com1.getImg() << endl;
    cout << "com2: 实部 = " << com2.getReal() << ", 虚部 = " << com2.getImg() << endl;

    // 测试 setReal() 和 setImg()
    com3.setReal(5.5);
    com3.setImg(6.6);
    cout << "com3: 实部 = " << com3.getReal() << ", 虚部 = " << com3.getImg() << endl;

    // 测试 calModulus()
    cout << "com1 的模 = " << com1.calModulus() << endl;

    // 测试加法
    CComplex com_add = com1 + com2;
    cout << "com1 + com2 = ";
    com_add.print();

    // 测试减法
    CComplex com_sub = com1 - com2;
    cout << "com1 - com2 = ";
    com_sub.print();

    // 测试乘法
    CComplex com_multi = com1 * com2;
    cout << "com1 * com2 = ";
    com_multi.print();

    // 测试除法
    CComplex com_div = com1 / com2;
    cout << "com1 / com2 = ";
    com_div.print();

    // 测试与实数的加法
    CComplex com_add_real = com1 + 2.0;
    cout << "com1 + 2.0 = ";
    com_add_real.print();

    // 测试与实数的减法
    CComplex com_sub_real = com1 - 2.0;
    cout << "com1 - 2.0 = ";
    com_sub_real.print();

    // 测试与实数的乘法
    CComplex com_multi_real = com1 * 2.0;
    cout << "com1 * 2.0 = ";
    com_multi_real.print();

    // 测试与实数的除法
    CComplex com_div_real = com1 / 2.0;
    cout << "com1 / 2.0 = ";
    com_div_real.print();

    // 测试前自增运算符
    ++com1;
    cout << "++com1 = ";
    com1.print();

    // 测试后自增运算符
    com1++;
    cout << "com1++ = ";
    com1.print();

    // 测试全局运算符重载
    CComplex com_global_add = 2.0 + com1;
    cout << "2.0 + com1 = ";
    com_global_add.print();

    CComplex com_global_sub = 2.0 - com1;
    cout << "2.0 - com1 = ";
    com_global_sub.print();

    CComplex com_global_multi = 2.0 * com1;
    cout << "2.0 * com1 = ";
    com_global_multi.print();

    CComplex com_global_div = 2.0 / com1;
    cout << "2.0 / com1 = ";
    com_global_div.print();

    return 0;
}
