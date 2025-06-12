#ifndef _COMPLEX_H
#define _COMPLEX_H

class CComplex
{
private:
    double m_img, m_real;//实数部分real，虚数部分img
public:
    CComplex(double, double);//参数顺序，先实部后虚部
    CComplex();//无参数

    double getReal();
    double getImg();
    double getReal() const;
    double getImg() const;


    void setReal(double);//set the real;
    void setImg(double);

    double calModulus() const;//取模

    CComplex Add(const CComplex&)const;  // 加法运算
    CComplex operator+(const CComplex&)const;
    CComplex Add(double)const;       // 复数与实数的加法运算
    CComplex operator+(double)const;

    CComplex Sub(const CComplex&)const;  // 减法运算
    CComplex operator-(const CComplex&)const;
    CComplex Sub(double)const;       // 复数与实数的减法运算
    CComplex operator-(double)const;

    CComplex Multi(const CComplex&)const;  // 乘法运算
    CComplex operator*(const CComplex&)const;
    CComplex Multi(double)const;     // 复数与实数的乘法运算
    CComplex operator*(double)const;

    CComplex Div(const CComplex&)const; //除法运算
    CComplex operator/(const CComplex&)const;
    CComplex Div(double)const;            // 复数与实数的除法运算
    CComplex operator/(double)const;

    CComplex& operator++();   // 前自增运算符重载函数，实现对实部和虚部都自增1
    CComplex operator++(int); // 后自增运算符重载函数，实现对实部和虚部都自增1

    void print()const;        // 将复数输出到屏幕，输出形式：实部+虚部i
};

CComplex operator+(double, const CComplex&);
CComplex operator-(double, const CComplex&);
CComplex operator*(double, const CComplex&);
CComplex operator/(double, const CComplex&);

#endif