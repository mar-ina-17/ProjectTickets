#ifndef THEATRE_H
#define THEATRE_H
#include <iostream>
#include <ostream>
#include "String.h"
#include "Vector.h"
#include "Play.h"
#include "Hall.h"

class Theatre
{
private:
    Vector<Play> plays;
    Vector<Hall> halls;

public:
    Theatre();
    Theatre(const Theatre &);
    Theatre &operator=(const Theatre &);

    void addHalls(const Vector<Hall> halls); //const
    void generateHalls(const int numOfHalls);
    void addPlays(const Vector<Play> plays); //const
    void addPlay(Play &play);

    void addEvent();
    void freeSeats() const;
    void bookSeat(); //high-order fn 4 both
    void unbookSeat();
    void buySeatForEvent();
    void bookedSeatsReport();

    size_t getPlaysSize() const;
    size_t getHallsSize() const;

    friend std::ostream &operator<<(std::ostream &out, const Theatre &other)
    {
        out << "Plays : " << std::endl;
        out << other.plays;
        std::cout << std::endl;
        out<<"Halls : "<<other.halls;
        return out;
    }
};

size_t Theatre::getPlaysSize() const
{
    return this->plays.getSize();
}

size_t Theatre::getHallsSize() const
{
    return this->halls.getSize();
}

Theatre::Theatre()
{
    //this->plays = Vector<Play>();
   // this->halls = Vector<Hall>();
	std::cout<<"Theatre constructed.";
}

Theatre::Theatre(const Theatre &other)
{
    this->halls = other.halls;
    this->plays = other.plays;
}

Theatre &Theatre::operator=(const Theatre &other)
{
    if (this != &other)
    {
        this->halls = other.halls;
        this->plays = other.plays;
    }
    return *this;
}

void Theatre::addHalls(Vector<Hall> halls)
{
    for (int i = 0; i < halls.getSize(); i++)
    {
        this->halls.push_back(halls[i]);
    }
}

void Theatre::addPlays(Vector<Play> plays)
{
    for (int i = 0; i < plays.getSize(); i++)
    {
        this->plays.push_back(plays[i]);
    }
}

void Theatre::addPlay(Play &play)
{
    this->plays.push_back(play);
}

void Theatre::generateHalls(const int numOfHalls) //add parametri 4 numer and hallnum
{
    for (int i = 0; i < numOfHalls; i++)
    {
        Hall newHall = Hall(i+2, i + 3, 1000 + i);
        this->halls.push_back(newHall);
    }
}

void Theatre::addEvent()
{
    Date date = Date();
    std::cin >> date;

    String name = String();
    std::cin >> name;

    size_t hallNumber;
    std::cin >> hallNumber;

    bool found = false;

    for (size_t i = 0, hallsSize = this->halls.getSize(); i < hallsSize; i++)
    {
        if (hallNumber == this->halls[i].getHallNumber())
        {
            found = true;
            this->halls[i].bookHall();
            Play newPlay = Play(date, name, this->halls[i]);
            this->plays.push_back(newPlay);
        }
    }

    if (!found)
    {
        char c;
        std::cout << "ERROR: Would you like to add another event in an existing hall or exit(y/n)?\n";
        std::cin >> c;
        if (c == 'y')
            addEvent();
        else
            exit(0);
    }
}

void Theatre::freeSeats() const
{
    Date date = Date();
    std::cin >> date;

    String name = String();
    std::cin >> name;

    bool found = false;
    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            std::cout << "Number of free seats: " << this->plays[i].getPlayHall().getFreeSeats();
        }
    }

    if (!found)
    {
        char c;
        std::cout << "ERROR: Would you like to check the free seats for another show or exit(y/n)?\n";
        std::cin >> c;
        if (c == 'y')
            freeSeats();
        else
            exit(0);
    }
}

void Theatre::bookSeat()
{
    size_t seatNumber;
    std::cin >> seatNumber;

    Date date = Date();
    std::cin >> date;

    String name = String();
    std::cin >> name;

    bool found = false;
    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            this->plays[i].getPlayHall().bookSeatInHall(seatNumber);
        }
    }
    if (!found)
    {
        char c;
        std::cout << "ERROR: Would you like to chose another seat or exit(y/n)?\n";
        std::cin >> c;
        if (c == 'y')
            bookSeat();
        else
            exit(0);
    }
}

void Theatre::unbookSeat()
{
    size_t seatNumber;
    std::cin >> seatNumber;

    Date date = Date();
    std::cin >> date;

    String name = String();
    std::cin >> name;

    bool found = false;
    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            this->plays[i].getPlayHall().unbookSeatInHall(seatNumber);
        }
    }
    if (!found)
    {
        char c;
        std::cout << "ERROR: Would you like to chose another seat or exit(y/n)?\n";
        std::cin >> c;
        if (c == 'y')
            unbookSeat();
        else
            exit(0);
    }
}

void Theatre::buySeatForEvent()
{
    size_t seatNumber;
    std::cin >> seatNumber;

    Date date = Date();
    std::cin >> date;

    String name = String();
    std::cin >> name;

    bool found = false;
    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            this->plays[i].getPlayHall().buySeatInHall(seatNumber);
        }
    }
    if (!found)
    {
        char c;
        std::cout << "ERROR: Would you like to buy another tcket or exit(y/n)?\n";
        std::cin >> c;
        if (c == 'y')
            buySeatForEvent();
        else
            exit(0);
    }
}

void Theatre::bookedSeatsReport()
{
    Date date = Date();
    String name = String();

    int choice = 0;
    std::cout << "Please, type 1, if u want to search by date, 2- name, 3- date and name:";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cin >> date;
        break;

    case 2:
        std::cin >> name;
        break;

    case 3:
        std::cin >> date >> name;
        break;
    }

    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (choice == 3)
        {
            if (this->plays[i].getPlayName() == name && this->plays[i].getPlayDate() == date)
            {
                std::cout << this->plays[i].getPlayHall();
                std::cout << "Total booked, but not bought seats for this play: " << this->plays[i].getPlayHall().getBookedSeats() << std::endl;
                std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            }
        }

        if (choice == 1)
        {
            if (this->plays[i].getPlayDate() == date)
            {
                std::cout << this->plays[i].getPlayHall();
                std::cout << "Total booked, but not bought seats for this play: " << this->plays[i].getPlayHall().getBookedSeats() << std::endl;
                std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            }
        }

        if (choice == 2)
        {
            if (this->plays[i].getPlayName() == name)
            {
                std::cout << this->plays[i].getPlayHall();
                std::cout << "Total booked, but not bought seats for this play: " << this->plays[i].getPlayHall().getBookedSeats() << std::endl;
                std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            }
        }
    }
}
#endif