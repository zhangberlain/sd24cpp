#ifndef _DATE_H
#define _DATE_H

class CDate
{
private:
   int m_year, m_month, m_day;
   int m_hour, m_min, m_second;
   int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;

   bool isRun(int)const;
public:
   //Constructor with default parameter values, in order£ºyear,month,day,hour,min,second
   CDate(int=0, int=1,int=1, int=0, int=0, int=0); 

   CDate tomorrow()const;      //get the date of tomorrow
   CDate yesterday()const;     //get the date of yesterday

   void setDate(const CDate&); //set date
   CDate getDate()const;        //get date

   bool isEqual(const CDate& d1); //true: equal to d1; false: not equal to d1

   void print()const;          //print date with format: yyyy-MM-dd hh:mm:ss
    
   
};

#endif 


