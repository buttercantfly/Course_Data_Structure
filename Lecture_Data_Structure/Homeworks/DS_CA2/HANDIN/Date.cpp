/**
 * Briefly explain the function of this class.
 *
 * @author 			游振彤
 * @ID 				  b08505018
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * Date.cpp
 * version 1.0
 */
#include <string>

#include "Date.h"

  /**
   *  Constructs a Date with the given month, day and year.   If the date is
   *  not valid, the entire program will halt with an error message.
   *  @param month is a month, numbered in the range 1...12.
   *  @param day is between 1 and the number of days in the given month.
   *  @param year is the year in question, with no digits omitted.
   *
   *  Grade: 15%
   */

  Date::Date(int month, int day, int year) {
    this -> month = month;
    this -> day = day;
    this -> year = year;
    if (isValidDate(month,day,year) == false){
      throw invalid_argument("This Date is invalid.");
    }
  };

  /**
   *  Constructs a Date object corresponding to the given string.
   *  @param s should be a string of the form "month/day/year" where month must
   *  be one or two digits, day must be one or two digits, and year must be
   *  between 1 and 4 digits.  If s does not match these requirements or is not
   *  a valid date, the program halts with an error message.
   *
   *  Grade: 30%
   */
  Date::Date(const string& s) {
    string re[3];
    int end = s.find("/");
    int start = 0;
    for (int i = 0; i <3 ;i++)
    {
        re[i] = s.substr(start, end - start);
        start = end + 1;
        end = s.find("/", start);
        if(i == 2){
          end = s[-1];
        }
    }
    this -> month = stoi(re[0]);
    this -> day = stoi(re[1]);
    this -> year = stoi(re[2]);
    if (isValidDate(month,day,year) == false){
      throw invalid_argument("This Date is invalid.");
    }
  };


  /**
   *  Checks whether the given year is a leap year.
   *  @return true if and only if the input year is a leap year.
   *
   *  Grade: 10%
   */

  bool Date::isLeapYear(int year) {
    if    (year % 4 == 0)
    {
      if  (year % 100 == 0 && year >= 100)
      {
        if(year % 400 == 0 && year >= 400)
        {
          return true;
        }
        else return false;
      }
      else return true;
    }
    else return false;
  }


  /**
   *  Returns the number of days in a given month.
   *  @param month is a month, numbered in the range 1...12.
   *  @param year is the year in question, with no digits omitted.
   *  @return the number of days in the given month.
   *
   *  Grade: 10%
   */
  int Date::daysInMonth(int month, int year) {
    if (month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12){
      return 31;
    }
    if (month == 2){
      if (isLeapYear(year) == true){
        return 29;
      }
      else{
        return 28;
      }
    }
    else{
      return 30;
    }                      // replace this line with your solution
  }


  /**
   *  Checks whether the given date is valid.
   *  @return true if and only if month/day/year constitute a valid date.
   *
   *  Years prior to A.D. 1 are NOT valid.
   *
   *  Grade: 20%
   */
  bool Date::isValidDate(int month, int day, int year) {
    if (year < 1){
      return false;
    }
    if (month < 1 || month > 12){
      return false;
    }
    if (day > daysInMonth(month,year)||day < 1){
        return false;
    }
    else{
      return true;
    }
  }

  /**
   *  Returns a string representation of this Date in the form month/day/year.
   *  The month, day, and year are expressed in full as integers; for example,
   *  10/17/2010 or 5/11/258.
   *  @return a String representation of this Date.
   *
   *  Grade: 20%
   */
  string Date::toString() {
    string dadada;
    dadada = to_string(this -> month) + "/" + to_string(this -> day) + "/" + to_string(this -> year);
    return dadada;
  }


  /**
   *  Determines whether this Date is before the Date d.
   *  @return true if and only if this Date is before d.
   *
   *  Grade: 10%
   */
  bool Date::isBefore(const Date& d) {
    if (this -> year < d.year){return true;}
    if (this -> year == d.year){
      if (this -> month < d.month){return true;}
      if (this -> month == d.month){
        if (this -> day < d.day){return true;}
        else return false;
      }
      else return false;
    }
    else return false;
  }


  /**
   *  Determines whether this Date is after the Date d.
   *  @return true if and only if this Date is after d.
   *
   *  Grade: 10%
   */
  bool Date::isAfter(const Date& d) {
    if (this -> year > d.year){return true;}
    if (this -> year == d.year){
      if (this -> month > d.month){return true;}
      if (this -> month == d.month){
        if (this -> day > d.day){return true;}
        else return false;
      }
      else return false;
    }
    else return false;
  }


  /**
   *  Determines whether this Date is equal to the Date d.
   *  @return true if and only if this Date is the same as d.
   *
   *  Grade: 10%
   */
  bool Date::isEqual(const Date& d){
    if (this->year == d.year && this -> month == d.month && this -> day == d.day)
    {
      return true;
    }
    else return false;
  }


  /**
   *  Returns the number of this Date in the year.
   *  @return a number n in the range 1...366, inclusive, such that this Date
   *  is the nth day of its year.  (366 is only used for December 31 in a leap
   *  year.)
   *
   *  Grade: 15%
   */
  int Date::dayInYear() {
    int days = 0;
    for (int i = 1;i < this -> month;i++){
      days = days + daysInMonth(i,this -> year);
    }
    days = days + this -> day;
    return days;
  }


  /** Determines the difference in days between d and this Date.  For example,
   *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
   *  If this Date occurs before d, the result is negative.
   *  @return the difference in days between d and this Date.
   *
   *  Grade: 10%
   */
  int Date::difference(const Date& d) {
    Date that = d;
    int answer = 0;
    int start = this -> year;
    int bora = -1;//Befroe or After (setup as Before)

    if(this -> isAfter(that) == true){
      bora = 1;
      start = that.year;
    }

    for(int i = 0;i < abs(this -> year - that.year);i++){
      if (isLeapYear(start + i) == true){
        answer = answer + 366;
      }
      else{
        answer = answer + 365;
      }
    }//Computing years

    answer = bora*answer + this -> dayInYear() - that.dayInYear();//Days
    return answer;
  }