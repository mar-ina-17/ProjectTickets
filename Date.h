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

        bool operator==(const Date&);

        friend std::istream& operator>>(std::istream&in, Date&other)
        {
            //change
            char delimiter;
			in>>other.year;
            in>>delimiter;
            in>>other.month;
            in>>delimiter;
            in>>other.day;

            if(other.day <= 0 || other.day > 31)
            {
                std::cout<<"Please, correct the day: ";
                in>>other.day;
            }

            if(other.month <= 0 || other.month > 12)
            {
                std::cout<<"Please, correct the month: ";
                in>>other.month;
            }
            
            if(other.year == 0 || other.year < 2021)
            {
                std::cout <<"Please, correct the year: ";
                in>>other.year;
            }

            if(other.month % 2 == 0) //mesecite ne sa ok 
            {
                if(other.day < 0 || other.day > 30)
                {
                    std::cout <<"Invalid date, please, change date. "<<std::endl;
                    return (in >> other);
                }
            }
            if (other.month == 2)
            {
                if((other.year % 4 == 0) && (other.year % 100 == 0) && (other.year % 400 == 0) && (other.day < 0 || other.day > 29))//proveri v google
                {
                    std::cout <<"Invalid date, please, change date. "<<std::endl;
                    return (in >> other);
                }
                if((other.year % 4 != 0) && (other.day < 0 || other.day > 28))
                {
                    std::cout <<"Invalid date, please, change date. "<<std::endl;
                    return (in >> other);
                }
            }

            else
            {
                if(other.day < 0 || other.day > 31)
                {
                    std::cout <<"Invalid date, please, change date. "<<std::endl;
                    return (in >> other);
                }
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

bool Date::operator==(const Date& other)
{
    if (this->day == other.day && this->month == other.month && this->year == other.year) return true;
    return false;
}
#endif