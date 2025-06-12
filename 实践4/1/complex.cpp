#include "complex.h"
#include <iostream>
#include <cmath>
/*
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
*/
CComplex::CComplex(double real ,double img )
{
    m_real = real;
    m_img = img;
}
CComplex::CComplex()
{
    m_real = 0;
    m_img = 0;
}
double CComplex::getImg()
{
    return m_img;
}
double CComplex::getReal()
{
    return m_real;
}
double CComplex::getReal()const
{
    return m_img;
}
double CComplex::getImg()const
{
    return m_real;
}

void CComplex::setReal(double real)//set the real;
{
    m_real = real;
}
void CComplex::setImg(double img)
{
    m_img = img;
}
double CComplex::calModulus() const//取模
{
    return pow(pow(m_img, 2)+pow(m_real, 2), 0.5);
}

CComplex CComplex::Add(const CComplex& com2)const  // 加法运算
{
    return CComplex((this->m_real + com2.m_real),(this->m_img + com2.m_img));
}
CComplex CComplex::operator+(const CComplex& com2)const
{
    return Add(com2);
}
CComplex CComplex::Add(double d)const       // 复数与实数的加法运算
{
    return CComplex((this->m_real + d),(this->m_img));
}
CComplex CComplex::operator+(double d)const
{
    return Add(d);
}

// 复数减法
CComplex CComplex::Sub(const CComplex& com2) const {
    return CComplex(m_real - com2.m_real, m_img - com2.m_img);
}

// 重载 - 运算符（复数 - 复数）
CComplex CComplex::operator-(const CComplex& com2) const {
    return Sub(com2);
}

// 复数与实数减法
CComplex CComplex::Sub(double d) const {
    return CComplex(m_real - d, m_img);
}

// 重载 - 运算符（复数 - 实数）
CComplex CComplex::operator-(double d) const {
    return Sub(d);
}

// 复数乘法
CComplex CComplex::Multi(const CComplex& com2) const {
    return CComplex(m_real * com2.m_real - m_img * com2.m_img,
                    m_real * com2.m_img + m_img * com2.m_real);
}

// 重载 * 运算符（复数 * 复数）
CComplex CComplex::operator*(const CComplex& com2) const {
    return Multi(com2);
}

// 复数与实数乘法
CComplex CComplex::Multi(double d) const {
    return CComplex(m_real * d, m_img * d);
}

// 重载 * 运算符（复数 * 实数）
CComplex CComplex::operator*(double d) const {
    return Multi(d);
}

// 复数除法
CComplex CComplex::Div(const CComplex& com2) const {
    try
    {
        double denominator = com2.m_real * com2.m_real + com2.m_img * com2.m_img;
    return CComplex((m_real * com2.m_real + m_img * com2.m_img) / denominator,
                    (m_img * com2.m_real - m_real * com2.m_img) / denominator);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return CComplex(0,0);
}

// 重载 / 运算符（复数 / 复数）
CComplex CComplex::operator/(const CComplex& com2) const {
    return Div(com2);
}

// 复数与实数除法
CComplex CComplex::Div(double d) const {
    return CComplex(m_real / d, m_img / d);
}

// 重载 / 运算符（复数 / 实数）
CComplex CComplex::operator/(double d) const {
    return Div(d);
}

CComplex& CComplex::operator++(){
    ++m_real;
    ++m_img;
    return *this;
}
CComplex CComplex::operator++(int) {
    CComplex temp = *this;
    ++(*this);
    return temp;
}

void CComplex::print() const {
    std::cout << m_real << (m_img >= 0 ? "+" : "") << m_img << "i" << std::endl;
}


// 非成员函数：double + CComplex
CComplex operator+(double d, const CComplex& com) {
    return com + d;
}

// 非成员函数：double - CComplex
CComplex operator-(double d, const CComplex& com) {
    return CComplex(d - com.getReal(), - com.getImg());
}

// 非成员函数：double * CComplex
CComplex operator*(double d, const CComplex& com) {
    return com * d;
}

// 非成员函数：double / CComplex
CComplex operator/(double d, const CComplex& com) {
    return CComplex(d, 0) / com;
}