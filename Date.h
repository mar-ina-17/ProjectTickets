#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>

class Date
{
    private:
        size_t day;
        size_t month;
        size_t year;
		char delimiter = '-';

    public:
        Date();
        Date(size_t day, size_t month, size_t year);
        Date(const Date&);

		bool isInputValid();

        bool operator==(const Date&);
		bool operator>=(const Date&);
		bool operator<(const Date& other);

		//! overloaded operator>> for Date
        friend std::istream& operator>>(std::istream&in, Date&other)
        {
			//! gets the user input with their own delimiter between the data
            char delimiter;
			in>>other.year>>delimiter>>other.month>>delimiter>>other.day;
			
			//! checks if the input for Date is not correct and returns the operator>> 
            if(!(other.isInputValid())) 
			{
				std::cout<<"Correct the date: ";
				return (in >> other);;
			}

			return in;
        }

		//! operator<< outputs the Date data in the console
        friend std::ostream& operator<<(std::ostream& out, const Date&other)
        {
            out<<other.year<<other.delimiter<<other.month<<other.delimiter<<other.day<<std::endl;
            return out;
        }

		//! declarations of ifstream and ofstream >> & <<
		friend std::ofstream& operator<<(std::ofstream& of, Date &other)
		{
			of<<other.year<<other.delimiter<<other.month<<other.delimiter<<other.day;
			return of;
		}

		friend std::ifstream& operator>>(std::ifstream&inf, Date&other)
		{
			inf>>other.year>>other.delimiter>>other.month>>other.delimiter>>other.day;					
			return inf;
		}

};
Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2021;
}

Date::Date(size_t day, size_t month, size_t year)
{
  this->day = day;
  this->month = month;
  this->year = year;  
} 

Date::Date(const Date& other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

//! bool function that validates the user input of the date
bool Date::isInputValid()
{
	//! limits the number used to determine day
	if(this->day <= 0 || this->day > 31)
	{
		return false;
	}

	//! limits the number used to determine month
	if(this->month <= 0 || this->month > 12)
	{
		return false;
	}

	//! limits the number used to determine year   
	if(this->year == 0 || this->year < 2021)
	{
		return false;
	}

		//! limits the number used to determine months with max 30 days
		if(this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)  
		{
			if(this->day < 0 || this->day > 30)
			{
				return false;
			}
		}

		//! limits the number used to determine February with max 29 days in each leap year and 28 regulary
		if (this->month == 2)
		{
			if((this->year % 4 == 0) && (this->year % 100 == 0) && (this->year % 400 == 0) && (this->day < 0 || this->day > 29))
			{
				return false;
			}
			if((this->year % 4 != 0) && (this->day < 0 || this->day > 28))
			{
				return false;
			}
		}

		//! limits the number used to determine months with max 31 days
		else
		{
			if(this->day < 0 || this->day > 31)
			{
				return false;
			}
		}

	return true;
}

//! boolean operator to determine equality between two Dates
bool Date::operator==(const Date& other)
{
    if (this->day == other.day && this->month == other.month && this->year == other.year) return true;
    return false;
}

//! boolean operator to determine the greater between two Dates
bool Date::operator>=(const Date& other)
{
	if ((this->year >= other.year) && (this->month >= other.month) && (this->day >= other.day)) return true;
	if ((this->year > other.year) && (this->month <= other.month) && (this->day < other.day)) return true;
	if ((this->year >= other.year) && (this->month >= other.month) && (this->day > other.day)) return true;
	
	else return false;
}

//! boolean operator to determine the smaller between two Dates
bool Date::operator<(const Date& other)
{
	return *this >= other;
}
#endif