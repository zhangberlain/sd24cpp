#include <iostream>
#include <cmath>

#ifndef _RATIONAL_H
#define _RATIONAL_H
class Rational{
    private:
    double m_double_num;
    int m_int_num;
    bool m_isint;//只有一直保持是整数的数才配的上分数,一旦与浮点数扯上关系,就不允许再和分数打交道了!

    int gcd(Rational)const;//求最大公因数
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
    //std::string div_fenshu(double)const;//不允许  :(
    std::string div_fenshu(int)const;

    Rational operator + (int)const;
    Rational operator - (int)const;
    Rational operator * (int)const;
    Rational operator / (int)const;//小数除法

    Rational operator + (double)const;
    Rational operator - (double)const;
    Rational operator * (double)const;
    Rational operator / (double)const;//小数除法

    Rational operator + (Rational)const;
    Rational operator - (Rational)const;
    Rational operator * (Rational)const;
    Rational operator / (Rational)const;//小数除法

    //friend std::istream& operator>>(std::istream& ,Rational&);
    //friend std::ostream& operator<<(std::ostream&, Rational&);// :(
    std::string print();
};

#endif
