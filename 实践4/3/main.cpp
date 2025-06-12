#include <iostream>
#include <cmath>
#include <iomanip>
#include "date.h"
/*class CDate
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
    
   
};*/
int main()
{
   using namespace std;

   cout << "test" << endl;
   int y, m, d, h, min, s;
   cin >> y >> m >> d >> h >> min >> s;
   CDate date1(y, m, d, h, min, s);
   cout << "test_tomorrow_yesterday" << endl;
   date1.print();
   CDate date2 = date1.tomorrow();
   CDate date3 = date1.yesterday();
   date2.print();
   date3.print();
   date2 = date1.getDate();
   date3.setDate(date1);
   date2.print();
   date3.print();
   cout  << "test one year" << endl;
   for(int i = 0; i < 366; i++)
   {
      date1 = date1.tomorrow();
      date1.print();
   }
   
}