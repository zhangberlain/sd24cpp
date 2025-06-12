#include "complex.h"
#include <iostream>
#include <cmath>
/*
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
double CComplex::calModulus() const//ȡģ
{
    return pow(pow(m_img, 2)+pow(m_real, 2), 0.5);
}

CComplex CComplex::Add(const CComplex& com2)const  // �ӷ�����
{
    return CComplex((this->m_real + com2.m_real),(this->m_img + com2.m_img));
}
CComplex CComplex::operator+(const CComplex& com2)const
{
    return Add(com2);
}
CComplex CComplex::Add(double d)const       // ������ʵ���ļӷ�����
{
    return CComplex((this->m_real + d),(this->m_img));
}
CComplex CComplex::operator+(double d)const
{
    return Add(d);
}

// ��������
CComplex CComplex::Sub(const CComplex& com2) const {
    return CComplex(m_real - com2.m_real, m_img - com2.m_img);
}

// ���� - ����������� - ������
CComplex CComplex::operator-(const CComplex& com2) const {
    return Sub(com2);
}

// ������ʵ������
CComplex CComplex::Sub(double d) const {
    return CComplex(m_real - d, m_img);
}

// ���� - ����������� - ʵ����
CComplex CComplex::operator-(double d) const {
    return Sub(d);
}

// �����˷�
CComplex CComplex::Multi(const CComplex& com2) const {
    return CComplex(m_real * com2.m_real - m_img * com2.m_img,
                    m_real * com2.m_img + m_img * com2.m_real);
}

// ���� * ����������� * ������
CComplex CComplex::operator*(const CComplex& com2) const {
    return Multi(com2);
}

// ������ʵ���˷�
CComplex CComplex::Multi(double d) const {
    return CComplex(m_real * d, m_img * d);
}

// ���� * ����������� * ʵ����
CComplex CComplex::operator*(double d) const {
    return Multi(d);
}

// ��������
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

// ���� / ����������� / ������
CComplex CComplex::operator/(const CComplex& com2) const {
    return Div(com2);
}

// ������ʵ������
CComplex CComplex::Div(double d) const {
    return CComplex(m_real / d, m_img / d);
}

// ���� / ����������� / ʵ����
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


// �ǳ�Ա������double + CComplex
CComplex operator+(double d, const CComplex& com) {
    return com + d;
}

// �ǳ�Ա������double - CComplex
CComplex operator-(double d, const CComplex& com) {
    return CComplex(d - com.getReal(), - com.getImg());
}

// �ǳ�Ա������double * CComplex
CComplex operator*(double d, const CComplex& com) {
    return com * d;
}

// �ǳ�Ա������double / CComplex
CComplex operator/(double d, const CComplex& com) {
    return CComplex(d, 0) / com;
}