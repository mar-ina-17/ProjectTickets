#ifndef THEATRE_H
#define THEATRE_H
#include <iostream>
#include "Play.h"
#include "Hall.h"

class Theatre
{
private:
    Vector<Play> plays;
    Vector<Hall> halls;

public:
	String name;
	Date date;
	int hallNumber;
	int seatNumber;

	void inputName();
	void inputDate();
	void inputHall();
	void inputSeat();

	void callMenu();
	void isFailed(bool);
	void displayHelp();


    Theatre();
    Theatre(const Theatre &);
    Theatre &operator=(const Theatre &);

    void addHalls(const Vector<Hall> halls);
    void generateHalls(const int numOfHalls);
    void addPlays(const Vector<Play> plays); 
    void addPlay(Play &play);

    void addEvent();
    const void freeSeats();
    void bookSeat();
    void unbookSeat();
    void buySeatForEvent();
    void bookedSeatsReport();
	void boughtReport();

    size_t getPlaysSize() const;
    size_t getHallsSize() const;

	void print();

    friend std::ostream &operator<<(std::ostream &out, const Theatre &other)
    {
        out << "Plays : " << std::endl;
        out << other.plays;
        std::cout << std::endl;
        out<<"Halls : "<<other.halls;
        return out;
    }

	friend std::ofstream &operator<<(std::ofstream &of, const Theatre &other)
    {
        of << "Plays : " << std::endl;
        of << other.plays;
        std::cout << std::endl;
        of<<"Halls : "<<other.halls;
        return of;
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

void Theatre::generateHalls(const int numOfHalls) 
{
    for (int i = 0; i < numOfHalls; i++)
    {
        Hall newHall = Hall(i+2, i + 3, 1000 + i);
        this->halls.push_back(newHall);
    }
}

void Theatre::print()
{
	std::cout << "Plays : " << std::endl;
	std::cout << this->plays;
	std::cout << std::endl;
	std::cout<<"Halls : "<<this->halls;
}
 //-------------------------------------------------------------------------------------------

 void Theatre::inputName()
 {	
	 String name1;
	 std::cout<<"Input name of play:";
	 std::cin>>name1;

 }

void Theatre::inputDate()
 {
	 std::cout<<"Input date:";
	 std::cin>>date;
 }

void Theatre::inputHall()
 {
	 std::cout<<"Input number of hall:";
	 std::cin>>hallNumber;
 }

void Theatre::inputSeat()
{
	std::cout<<"Input number of seat:";
	std::cin>>seatNumber;
}

void Theatre::isFailed(bool is)
{
	if(!is) std::cout<<"ERROR: Operation Failed."<<std::endl;
	this->callMenu();
}

void Theatre::addEvent()
{
    inputDate();
	inputHall();
	inputName();
	
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

    isFailed(found);
}

const void Theatre::freeSeats()
{
   	inputDate();	
	inputName();

    bool found = false;
	std::cout<<name;
    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            std::cout << "Number of free seats: " << this->plays[i].getPlayHall().getFreeSeats()<<std::endl;
        }
    }

 	isFailed(found);

}

void Theatre::bookSeat()
{
    inputSeat();
	inputDate();
	inputName();

    bool found = false;

    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            this->plays[i].getPlayHall().bookSeatInHall(seatNumber);
        }
    }
    
	isFailed(found);

}

void Theatre::unbookSeat()
{
    inputSeat();
	inputDate();
	inputName();

    bool found = false;

    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            this->plays[i].getPlayHall().unbookSeatInHall(seatNumber);
        }
    }
    
	isFailed(found);
}

void Theatre::buySeatForEvent()
{
    inputSeat();
	inputDate();
	inputName();

    bool found = false;

    for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() == date && this->plays[i].getPlayName() == name)
        {
            found = true;
            this->plays[i].getPlayHall().buySeatInHall(seatNumber);
        }
    }
	
	isFailed(found);
}

void Theatre::bookedSeatsReport()
{

    int choice = 0;
    std::cout << "Please, type 1, if u want to search by date, 2- name, 3- date and name:";
    std::cin >> choice;

    switch (choice)
    {
		case 1: inputDate();  break;
		case 2: inputName();  break;
		case 3:	
			inputDate();
			inputName();
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

void Theatre::boughtReport()
{
	Date date2;
	inputDate();
	std::cout<<"to date: ";
	std::cin>>date2;

	if(date < date2) return;

	inputHall();
	bool found = false;
	for (size_t i = 0; i < this->plays.getSize(); i++)
    {
        if (this->plays[i].getPlayDate() >= date && this->plays[i].getPlayDate() < date2 && this->plays[i].getPlayHall().getHallNumber() == hallNumber)
        {
            found = true;
            std::cout<<"For date: "<< this->plays[i].getPlayDate()<<"this hall has :"<< this->plays[i].getPlayHall().getBoughtSeats()<<std::endl;;
        }
    }
	
	isFailed(found);
}

void Theatre::displayHelp()
{
    std::cout <<"0 - exit program" << std::endl;
    std::cout <<"1 - addevent <date> <hall> <name> -- Adds a new event of date <date> named <name> in the <hall> hall.\n";
    std::cout <<"2 - freeseats <date> <name> -- Displays a free space for a performance named <name> on <date> (unsold and unsaved tickets).\n";
    std::cout <<"3 - book <seat> <date> <name> -- Saves a show ticket named <name> to <date> on line <row> and place <seat>.\n";
    std::cout <<"4 - unbook <seat> <date> <name> -- Cancel a reservation for a show named <name> on <date> on line <row> and place <seat>.\n";
    std::cout <<"5 - buy <seat> <date> <name> -- Purchases a ticket for a show named <name> on <date> at <seat>.\n";
    std::cout <<"6 - bookings [<date>] [<name>] -- Displays saved but unpaid (unpurchased) performance tickets named <name> on <date>. If <name> is omitted, displays information about all performances on the given date. If <date> is omitted, displays information about all dates.\n";
	std::cout <<"7 - report <from> <to> [<hall>] -- Displays a reference for purchasing tickets from date <from> to date <to> in hall <hall>, displaying all presented performances in the hall and for each individual presentation the quantity of sold tickets is also displayed.\n";
    std::cout <<"8 - help\n";
	std::cout <<"9 - print theatre\n";

}

void Theatre::callMenu()
{
	
	size_t command;
	std::cout<<"Input command: ";
	std::cin>>command;
    
        if(command == 1)
        {
            std::cout <<"You can now add an event:\n";
            addEvent();
           	callMenu();
        }

        if(command == 2)
        {
            std::cout <<"You can now check for free seats at an event:\n";
            freeSeats();
            callMenu();
        }

        if(command == 3)
        {
            std::cout <<"You can now book a seat at an event:\n";
            bookSeat();            
          	callMenu();
        } 

        if(command == 4) 
        {
            std::cout <<"You can now unbook a seat at an event:\n";
            unbookSeat();
            callMenu();
        }

        if(command == 5) 
        {
            std::cout <<"You can now buy a seat at an event:\n";
           	buySeatForEvent();
            callMenu();
        }
        if(command == 6)
        {
            std::cout <<"You can now see the amount of booked seats at an event:\n";
            bookedSeatsReport();
            callMenu();
        } 
        if(command == 7)
        {
            std::cout <<"You can now see the amount of booked seats at an event:\n";
            boughtReport();
            callMenu();
        } 
		if(command == 8)
		{
			displayHelp();
			callMenu();
		}
		if(command == 9)
		{
			print();
			callMenu();
		}
}
#endif