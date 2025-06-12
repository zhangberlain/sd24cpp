#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
#include "rational.h"
/*class Rational{
    private:
    bool m_isint;//ֻ��һֱ��������������������Ϸ���,һ���븡�������Ϲ�ϵ,�Ͳ������ٺͷ����򽻵���!
    int m_int_num;
    double m_double_num;

    int gcd(Rational)const;//���������
    int gcd(int)const;
    public:
    Rational();
    Rational(int x);
    Rational(double x); 

    int get_int(void);
    double get_double(void);


    
    Rational plus(Rational)const;
    Rational plus(double)const;
    Rational plus(int)const;


    Rational sub(Rational)const;
    Rational sub(double)const;
    Rational sub(int)const;

    Rational multi(Rational)const;
    Rational multi(double)const;
    Rational multi(int)const;

    Rational div(Rational)const;
    Rational div(double)const;
    Rational div(int)const;
    std::string div_fenshu(Rational)const;
    //std::string div_fenshu(double)const;//������  :(
    std::string div_fenshu(int)const;

    Rational operator + (int)const;
    Rational operator - (int)const;
    Rational operator * (int)const;
    Rational operator / (int)const;//С������

    Rational operator + (double)const;
    Rational operator - (double)const;
    Rational operator * (double)const;
    Rational operator / (double)const;//С������

    Rational operator + (Rational)const;
    Rational operator - (Rational)const;
    Rational operator * (Rational)const;
    Rational operator / (Rational)const;//С������

    //friend std::istream& operator>>(std::istream& ,Rational&);
    //friend std::ostream& operator<<(std::ostream&, Rational&);
    std::string print();
};
*/

Rational::Rational(int x):m_isint{true},m_int_num{x},m_double_num{double(x)}
{
}
Rational::Rational(double x):m_isint{false},m_int_num{int(x)},m_double_num{x}
{
}
Rational::Rational():m_isint{true},m_int_num{0},m_double_num{0}
{
}
Rational Rational::plus(Rational x)const
{
    if(x.m_isint && this->m_isint)
    {return Rational(this->m_int_num + x.m_int_num);}
    return Rational(this->m_double_num + x.m_double_num);
}
Rational Rational::plus(double x)const{

    return Rational(this->m_double_num + x);
}
Rational Rational::plus(int x)const
{
    if(this->m_isint)
    {return Rational(x + this->m_int_num);}
    return Rational(x + this->m_double_num);
}
Rational Rational::sub(Rational x) const {
    if (x.m_isint && this->m_isint) {
        return Rational(this->m_int_num - x.m_int_num);
    }
    return Rational(this->m_double_num - x.m_double_num);
}

Rational Rational::sub(double x) const {
    return Rational(this->m_double_num - x);
}

Rational Rational::sub(int x) const {
    if (this->m_isint) {
        return Rational(this->m_int_num - x);
    }
    return Rational(this->m_double_num - x);
}

// �˷�ʵ��
Rational Rational::multi(Rational x) const {
    if (x.m_isint && this->m_isint) {
        return Rational(this->m_int_num * x.m_int_num);
    }
    return Rational(this->m_double_num * x.m_double_num);
}

Rational Rational::multi(double x) const {
    return Rational(this->m_double_num * x);
}

Rational Rational::multi(int x) const {
    if (this->m_isint) {
        return Rational(this->m_int_num * x);
    }
    return Rational(this->m_double_num * x);
}

// ����ʵ��
Rational Rational::div(Rational x) const {
    if (x.m_isint && x.m_int_num == 0) {
        throw std::invalid_argument("Division by zero �����������");
    }
    if (!x.m_isint && (x.m_double_num < 0.000001 && x.m_double_num > -0.000001)) {
        throw std::invalid_argument("Division by zero �����������");
    }
    if (x.m_isint && this->m_isint) {
        if(this->m_int_num % x.m_int_num == 0)
        {return Rational(this->m_int_num / x.m_int_num);}
    }
    return Rational(this->m_double_num / x.m_double_num);
}

Rational Rational::div(double x) const {
    if (x < 0.000001 && x > -0.000001) {
        throw std::invalid_argument("Division by zero �����������");
    }
    return Rational(this->m_double_num / x);
}

Rational Rational::div(int x) const {
    if (x == 0) {
        throw std::invalid_argument("Division by zero �����������");
    }
    if (this->m_isint && this->m_int_num % x == 0) {
        return Rational(this->m_int_num / x);
    }
    return Rational(this->m_double_num / x);
}

std::string Rational::div_fenshu(Rational x)const{
    if(!this->m_isint || !x.m_isint)
    {
        throw std::invalid_argument("С����Ҫ�ͷ�����һ��");
    }
    int fex_up = this->m_int_num/this->gcd(x);
    int fex_down = x.m_int_num/this->gcd(x);
    std::string str_res = std::to_string(fex_up) + "/" + std::to_string(fex_down);
    return str_res;
}
std::string Rational::div_fenshu(int x)const{
    if(!this->m_isint )
    {
        throw std::invalid_argument("С����Ҫ�ͷ�����һ��");
    }
    int fex_up = this->m_int_num/this->gcd(x);
    int fex_down = x/this->gcd(x);
    std::string str_res = std::to_string(fex_up) + "/" + std::to_string(fex_down);
    return str_res;
}

Rational Rational::operator+(int x) const {
    return this->plus(x);
}

Rational Rational::operator+(double x) const {
    return this->plus(x);
}

Rational Rational::operator+(Rational x) const {
    return this->plus(x);
}
Rational Rational::operator-(int x) const {
    return this->sub(x);
}

Rational Rational::operator-(double x) const {
    return this->sub(x);
}

Rational Rational::operator-(Rational x) const {
    return this->sub(x);
}
Rational Rational::operator*(int x) const {
    return this->multi(x);
}

Rational Rational::operator*(double x) const {
    return this->multi(x);
}

Rational Rational::operator*(Rational x) const {
    return this->multi(x);
}
Rational Rational::operator/(int x) const {
    return this->div(x);
}

Rational Rational::operator/(double x) const {
    return this->div(x);
}

Rational Rational::operator/(Rational x) const {
    return this->div(x);
}
    
int Rational::gcd(Rational x)const//���������
{
    int gcd_int = 0;
    for(int i = 1; i < std::min(this->m_int_num, x.m_int_num)+1; ++i)
    {
        if(this->m_int_num % i == 0 && x.m_int_num % i == 0)
        {
            gcd_int = i;
        }
    }
    return gcd_int;
}
int Rational::gcd(int x)const
{
    {
    int gcd_int = 0;
    for(int i = 1; i < std::min(this->m_int_num, x)+1; ++i)
    {
        if(this->m_int_num % i == 0 && x % i == 0)
        {
            gcd_int = i;
        }
    }
    return gcd_int;
}
}

int Rational::get_int(void)
{
    return this->m_int_num;
}
double Rational::get_double(void)
{
    return this->m_double_num;
}
/*
std::istream& operator>>(std::istream& is, Rational& r)
{
    std::string input;
    is >> input;
    try//�ȿ��ǲ�������
    {
        r.m_int_num = std::stoi(input);
        r.m_double_num = std::stod(input);
        r.m_isint = true;
    }
    catch(const std::invalid_argument&)
    {
        try
        {
            r.m_int_num = int(std::stod(input));
            r.m_double_num = std::stod(input);
            r.m_isint = false;
        }
        
        catch(const std::invalid_argument&)
        {
            throw std::invalid_argument("ֻ������һ����");
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Rational& r)
{
    if(r.m_isint)
    {
        os << std::to_string(r.m_int_num);
    }
    else
    {
        os << std::to_string(r.m_double_num);
    }
    return os;
}*/

std::string Rational::print()
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(4);
    if(m_isint){
        oss << m_int_num;
    }
    else{
        oss << m_double_num;
    }
    return oss.str();
}