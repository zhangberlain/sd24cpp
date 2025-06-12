#include <iostream>
#include "complex.h"

using namespace std;
int main() {
    // ���Թ��캯��
    CComplex com1(1.1, 1.2);
    CComplex com2(3.0, 4.0);
    CComplex com3;

    // ���� getReal() �� getImg()
    cout << "com1: ʵ�� = " << com1.getReal() << ", �鲿 = " << com1.getImg() << endl;
    cout << "com2: ʵ�� = " << com2.getReal() << ", �鲿 = " << com2.getImg() << endl;

    // ���� setReal() �� setImg()
    com3.setReal(5.5);
    com3.setImg(6.6);
    cout << "com3: ʵ�� = " << com3.getReal() << ", �鲿 = " << com3.getImg() << endl;

    // ���� calModulus()
    cout << "com1 ��ģ = " << com1.calModulus() << endl;

    // ���Լӷ�
    CComplex com_add = com1 + com2;
    cout << "com1 + com2 = ";
    com_add.print();

    // ���Լ���
    CComplex com_sub = com1 - com2;
    cout << "com1 - com2 = ";
    com_sub.print();

    // ���Գ˷�
    CComplex com_multi = com1 * com2;
    cout << "com1 * com2 = ";
    com_multi.print();

    // ���Գ���
    CComplex com_div = com1 / com2;
    cout << "com1 / com2 = ";
    com_div.print();

    // ������ʵ���ļӷ�
    CComplex com_add_real = com1 + 2.0;
    cout << "com1 + 2.0 = ";
    com_add_real.print();

    // ������ʵ���ļ���
    CComplex com_sub_real = com1 - 2.0;
    cout << "com1 - 2.0 = ";
    com_sub_real.print();

    // ������ʵ���ĳ˷�
    CComplex com_multi_real = com1 * 2.0;
    cout << "com1 * 2.0 = ";
    com_multi_real.print();

    // ������ʵ���ĳ���
    CComplex com_div_real = com1 / 2.0;
    cout << "com1 / 2.0 = ";
    com_div_real.print();

    // ����ǰ���������
    ++com1;
    cout << "++com1 = ";
    com1.print();

    // ���Ժ����������
    com1++;
    cout << "com1++ = ";
    com1.print();

    // ����ȫ�����������
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
