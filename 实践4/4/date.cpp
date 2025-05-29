#include <iostream>
#include "date.h"
/*
class CDate
{
private:
   int m_year, m_month, m_day;
   int m_hour, m_min, m_second;
   int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;

   bool isRun(int)const;
public:
   //Constructor with default parameter values, in order：year,month,day,hour,min,second
   CDate(int=0, int=1,int=1, int=0, int=0, int=0); 

   CDate tomorrow()const;      //get the date of tomorrow
   CDate yesterday()const;     //get the date of yesterday

   void setDate(const CDate&); //set date
   CDate getDate()const;        //get date

   bool isEqual(const CDate& d1); //true: equal to d1; false: not equal to d1

   void print()const;          //print date with format: yyyy-MM-dd hh:mm:ss
    
   
};*/
bool CDate::isRun(int x)const
{
    if(x%4 == 0)
    {
        if(x%100 == 0 && !(x%400 == 0))
        {
            return false;
        }
        return true;
    }
    return false;
}

CDate::CDate(int year , int month,int day, int hour, int min, int second):
                m_year(year),
                m_month(month),
                m_day(day),
                m_hour(hour),
                m_min(min),
                m_second(second)
{
    if(year> 9000)
    {
        throw std::invalid_argument("年份错误（小于9000）");
    }
    if(month > 12 || month < 1)
    {
        throw std::invalid_argument("月份错误");
    }
    if(month == 2)
    {
        if(this -> isRun(year) && day > 29)
        {
            throw std::invalid_argument("日期过大");
        }
        if(!(this -> isRun(year)) && day > 28)
        {
            throw std::invalid_argument("日期过大");
        }
    }
    else if(day > month_day[month-1])
    {
        throw std::invalid_argument("日期过大");
    }
    if(hour > 24 || min > 59 || second > 59)
    {
        throw std::invalid_argument("时间超过限制");
    }
    if(year < 1 || month < 1 || day < 1|| hour < 0|| min < 0|| second < 0)
    {
        throw std::invalid_argument("日期时间不能为负");
    }
}
CDate CDate::tomorrow()const
{
    if(this-> m_day < this->month_day[m_month-1])//没到月末
    {
        return CDate(m_year,m_month,m_day+1,m_hour,m_min,m_second);
    }
    else if(m_day == 28 && m_month == 2 && !(this->isRun(this -> m_year)))//特殊情况:非闰年的228
    {
        return CDate(m_year,3,1,m_hour,m_min,m_second);
    }
    else if(m_day == 28 && m_month == 2 && this->isRun(this -> m_year))//特殊情况:闰年的228(不用下个月)
    {
        return CDate(m_year,m_month,m_day+1,m_hour,m_min,m_second);
    }
    else if(m_day == 29 && m_month == 2 && this->isRun(this -> m_year))//特殊情况:闰年的229(下个月)
    {
        return CDate(m_year,3,1,m_hour,m_min,m_second);
    }
    else if(this -> m_day == this->month_day[m_month-1] && !(this->m_month == 12))//月末下个月
    {
        return CDate(m_year,m_month+1,1,m_hour,m_min,m_second);
    }
    else if(this -> m_day == this->month_day[m_month-1] && this->m_month == 12)//年末下一年
    {
        return CDate(m_year+1,1,1,m_hour,m_min,m_second);
    }
}
CDate CDate::yesterday()const
{
    if(this-> m_day > 1)
    {
        return CDate(m_year,m_month,m_day-1,m_hour,m_min,m_second);
    }
    else if(this -> m_day == 1 && this->m_month == 3 && this->isRun(m_year))
    {
        return CDate(m_year,2,29,m_hour,m_min,m_second);
    }
    else if(this -> m_day == 1 && this->m_month == 3 && !(this->isRun(m_year)))
    {
        return CDate(m_year,2,28,m_hour,m_min,m_second);
    }
    else if(this -> m_day == 1 && !(this->m_month == 1))
    {
        return CDate(m_year,m_month-1,this->month_day[m_month-2],m_hour,m_min,m_second);
    }
    else if(this -> m_day == 1 && this->m_month == 1)
    {
        return CDate(m_year-1,12,31,m_hour,m_min,m_second);
    }
}

void CDate::setDate(const CDate& cd)
{
    this->m_year = cd.m_year;
    this->m_month = cd.m_month;
    this->m_day = cd.m_day;
    this->m_hour = cd.m_hour;
    this->m_min = cd.m_min;
    this->m_second = cd.m_second;
}
CDate CDate::getDate(void)const
{
    return CDate(m_year,m_month,m_day,m_hour,m_min,m_second);
}

bool CDate::isEqual(const CDate& cd)
{
    return (this->m_year == cd.m_year &&
            this->m_month == cd.m_month &&
            this->m_day == cd.m_day &&
            this->m_hour == cd.m_hour &&
            this->m_min == cd.m_min &&
            this->m_second == cd.m_second);
}

void CDate::print(void) const
{
    std::cout << m_year << "-" << m_month << "-" << m_day << " " << m_hour << "-" << m_min << "-" << m_second << std::endl;
}