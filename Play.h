#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <ostream>
#include "String.h"
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
        Play(const Date playDate, const String playName, const Hall playHall);
        Play(const Play&);
        Play& operator=(const Play&);
        
        Hall getPlayHall() const
        {
            return this->playHall;
        }
        
        Date getPlayDate() const
        {
            return this->playDate;
        }

        String getPlayName() const
        {
            return this->playName;
        }

        void setPlayDate(Date date);
        void setPlayName(String name);
        void setPlayHall(Hall hall);

        void print() const;
    

        friend std::istream& operator>>(std::istream& in, Play& other)
        {
            std::cout<<"Insert play's date: ";
            in>>other.playDate;
            
            in>>other.playHall;

            std::cout<<"Insert play's name: ";
            in.ignore();
            in>>other.playName;

            return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const Play&other)
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
    this->playHall = Hall();
}

Play::Play(const Date date, const String name, const Hall hall)
{
    this->playName =  name;
    this->playDate = date;
    this->playHall = hall;
}

Play::Play(const Play& other)
{
    this->playDate = other.playDate;
    this->playName = other.playName;
    this->playHall = other.playHall;
}

Play& Play::operator=(const Play& other)
{
    if(this != &other)
    {
        this->playDate = other.playDate;
        this->playName = other.playName;
        this->playHall = other.playHall;
    }
    return *this;
}

void Play::print() const
{
    std::cout <<this->playDate;
    std::cout <<this->playName;
    std::cout <<this->playHall;
}

void Play::setPlayDate(Date date)
{
    this->playDate = date;
}

void Play::setPlayName(String name)
{
   this->playName = name;
}

void Play::setPlayHall(Hall hall)
{
    this->playHall = hall;
}
#endif