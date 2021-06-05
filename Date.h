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


        friend std::istream& operator>>(std::istream&in, Date&other)
        {
            char delimiter;
			in>>other.year>>delimiter>>other.month>>delimiter>>other.day;

            if(!(other.isInputValid())) 
			{
				std::cout<<"Correct the date: ";
				return (in >> other);;
			}

			return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const Date&other)
        {
            out<<other.year<<other.delimiter<<other.month<<other.delimiter<<other.day<<std::endl;
            return out;
        }

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

bool Date::isInputValid()
{
	if(this->day <= 0 || this->day > 31)
            {
                return false;
            }

            if(this->month <= 0 || this->month > 12)
            {
                return false;
            }
            
            if(this->year == 0 || this->year < 2021)
            {
                return false;
            }

            if(this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)  
            {
                if(this->day < 0 || this->day > 30)
                {
                    return false;
                }
            }

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

            else
            {
                if(this->day < 0 || this->day > 31)
                {
                    return false;
                }
            }
	return true;
}

bool Date::operator==(const Date& other)
{
    if (this->day == other.day && this->month == other.month && this->year == other.year) return true;
    return false;
}

bool Date::operator>=(const Date& other)
{
	if ((this->year >= other.year) && (this->month >= other.month) && (this->day >= other.day)) return true;
	if ((this->year > other.year) && (this->month <= other.month) && (this->day < other.day)) return true;
	if ((this->year >= other.year) && (this->month >= other.month) && (this->day > other.day)) return true;
	
	else return false;
}

bool Date::operator<(const Date& other)
{
	return *this >= other;
}
#endif