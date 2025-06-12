#ifndef _COMPLEX_H
#define _COMPLEX_H

class CComplex
{
private:
    double m_img, m_real;//ʵ������real����������img
public:
    CComplex(double, double);//����˳����ʵ�����鲿
    CComplex();//�޲���

    double getReal();
    double getImg();
    double getReal() const;
    double getImg() const;


    void setReal(double);//set the real;
    void setImg(double);

    double calModulus() const;//ȡģ

    CComplex Add(const CComplex&)const;  // �ӷ�����
    CComplex operator+(const CComplex&)const;
    CComplex Add(double)const;       // ������ʵ���ļӷ�����
    CComplex operator+(double)const;

    CComplex Sub(const CComplex&)const;  // ��������
    CComplex operator-(const CComplex&)const;
    CComplex Sub(double)const;       // ������ʵ���ļ�������
    CComplex operator-(double)const;

    CComplex Multi(const CComplex&)const;  // �˷�����
    CComplex operator*(const CComplex&)const;
    CComplex Multi(double)const;     // ������ʵ���ĳ˷�����
    CComplex operator*(double)const;

    CComplex Div(const CComplex&)const; //��������
    CComplex operator/(const CComplex&)const;
    CComplex Div(double)const;            // ������ʵ���ĳ�������
    CComplex operator/(double)const;

    CComplex& operator++();   // ǰ������������غ�����ʵ�ֶ�ʵ�����鲿������1
    CComplex operator++(int); // ��������������غ�����ʵ�ֶ�ʵ�����鲿������1

    void print()const;        // �������������Ļ�������ʽ��ʵ��+�鲿i
};

CComplex operator+(double, const CComplex&);
CComplex operator-(double, const CComplex&);
CComplex operator*(double, const CComplex&);
CComplex operator/(double, const CComplex&);

#endif