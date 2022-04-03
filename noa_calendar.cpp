#include <iostream>
using namespace std;
// PRE: a year greater or equal than 1900
// POST: returns whether that year was a leap year
int is_leap_year(unsigned int year) {
  //To be implemented
  if (year >= 1900 && year%4 == 0)
  {
    return 1;
  }
  else{

    return 0;
  }
}

// PRE: a year greater or equal than 1900
// POST: returns the number of days in that year
unsigned int count_days_in_year(unsigned int year) {
  //To be implemented
  if (is_leap_year(year))
  {
    return 366;
  }

  else
  {
    return 365;
  }
}

// PRE: a month between 1 and 12 and a year greater or equal than 1900
// POST: returns the number of days in the month of that year
unsigned int count_days_in_month (unsigned int month, unsigned int year) {
  //To be implemented
  if (!is_leap_year(year))
  {

    if (month==4||6||9||11)
    {

      return 30;
    }

    else if(month==2)
    {
      return 28;
    }

    else{
      return 31;
    }
  }
  else
  {

    if (month==4||6||9||11){

      return 30;
    }

    else if(month==2){
      return 29;
    }

    else{
      return 31;
    }
  }
}

// POST: returns whether the given values represent a valid date
bool is_valid_date(unsigned int day, unsigned int month, unsigned int year) {
  bool giorno;
  bool mese;
  bool anno;

    if (1<=day<=count_days_in_month(month, year))
    {
      giorno = true;
    }
    if (1<=month<=12){ 
      mese = true ;
    }
    if (year >=1900){
      anno = true;
    }
    if (giorno&&mese&&anno){
    return true;
    }
    else {
      return false;
    }
}

// PRE: the given values represent a valid date
// POST: returns the number of days between January 1, 1900 and this date
//TODO
unsigned int count_days(unsigned int day, unsigned int month, unsigned int year) {
  //To be implemented

  int counter=0;
  int counter2=0;


  for (int j=year; j>=1900;j--){
    counter+=count_days_in_year(j);
  }

  for (int l=month + 1;l<=12; l++){
    counter2+=count_days_in_month(l);
  }
  int counter_days = 0;
  counter_days+=count_days_in_month(month, year);
  counter_days-= day;

  return counter-counter2-counter_days;

  return 0;
}


// PRE: the given values represent a (potentially invalid) date
// POST: prints the weekday if the date is valid or "invalid date" otherwise.
//      Everything must be printed in lowercase.
//TODO
void print_weekday(unsigned int day, unsigned int month, unsigned int year){
  if (is_valid_date(day, month, year))
  {
      return;
  }
  else
  {
      cout <<"invalid date";
  }

}

int main()
{
    return 0;
}