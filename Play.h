#ifndef PLAY_H
#define PLAY_H
#include <iostream>
//#include "String.h"
#include "Hall.h"
#include "Date.h"

class Play
{
    private:
        Date playDate;
        String playName;
        Hall playHall;

    public:
        Play();
        Play(const Date &playDate, const String &playName, const Hall& playHall);//&
        Play(const Play&);
        
        Hall getPlayHall() const;
        Date getPlayDate() const;
        String getPlayName() const;

        void setPlayDate(Date &date);
        void setPlayName(String &name);
        void setPlayHall(Hall& hall);
    

        friend std::istream& operator>>(std::istream& in, Play& other)
        {
            std::cout<<"Insert play's name: ";
            in>>other.playName;
			
			std::cout<<"Insert play's date: ";
            in>>other.playDate;
			
			in>>other.playHall;

            return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const Play&other)
        {
            out<<"Play's date: "<<other.playDate;
            out<<"Play's name: "<<other.playName<<std::endl;
           	out<<other.playHall<<std::endl;

            return out;
        }

		friend std::ofstream& operator<<(std::ofstream& out, Play&other)
        {
            out<<"Play's date: "<<other.playDate;
            out<<"Play's name: "<<other.playName<<std::endl;
           	out<<other.playHall<<std::endl;

            return out;
        }
};

Play::Play()
{
	this->playDate = Date();
    this->playName = String("Test play name");
}

Play::Play(const Date &date, const String &name, const Hall &hall)
{
    this->playName = name;
    this->playDate = date;
    this->playHall = hall;
}

Play::Play(const Play& other)
{
    this->playDate = other.playDate;
    this->playName = other.playName;
    this->playHall = other.playHall;
}

void Play::setPlayDate(Date &date)
{
    this->playDate = date;
}

void Play::setPlayName(String &name)
{
   this->playName = name;
}

void Play::setPlayHall(Hall &hall)
{
    this->playHall = hall;
}

Hall Play::getPlayHall() const
{
	return this->playHall;
}

Date Play::getPlayDate() const
{
	return this->playDate;
}

String Play::getPlayName() const
{
	return this->playName;
}

#endif