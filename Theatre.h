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
	void returnBookedSeatsHelper(int);
    void bookedSeatsReport();
	void boughtReport();

    size_t getPlaysSize() const;
    size_t getHallsSize() const;

	void print();

	//! overloaded operator<< to print a Theatre to the console
    friend std::ostream &operator<<(std::ostream &out, const Theatre &other)
    {
        out << "Plays : " << std::endl;
        out << other.plays;
        std::cout << std::endl;
        out<<"Halls : "<<other.halls;
        return out;
    }

	//! overloaded operator<< to print a Theatre to a file
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

//! a method that adds a vector of halls to the current this->halls 
void Theatre::addHalls(Vector<Hall> halls)
{
    for (int i = 0; i < halls.getSize(); i++)
    {
        this->halls.push_back(halls[i]);
    }
}

//! a method that adds a vector of plays to the current this->plays 
void Theatre::addPlays(Vector<Play> plays)
{
    for (int i = 0; i < plays.getSize(); i++)
    {
        this->plays.push_back(plays[i]);
    }
}

//! a method that adds a single Play to the vector
void Theatre::addPlay(Play &play)
{
    this->plays.push_back(play);
}

//! a method that generates a given amount of halls in the Theatre 
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

//! helpers for the users input as for the 
//! name of the play, date, hall number and seat number

 void Theatre::inputName()
 {		
	 std::cout<<"Input name of play:";
	 std::cin>>name;
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

//! helper for one of the methods as this piece of code happens to be repeated
void Theatre::returnBookedSeatsHelper(int i)
{
	 std::cout << this->plays[i].getPlayHall();
	std::cout << "Total booked, but not bought seats for this play: " << this->plays[i].getPlayHall().getBookedSeats() << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
}

//! checks if the operation is not executed successfuly and calls the menu again
void Theatre::isFailed(bool is)
{
	if(!is) std::cout<<"ERROR: Operation Failed.";
	callMenu();
}

//! FUNCTIONALITIES OF THE PROGRAM : 

//! adds an event to the Theatre, by getting the users input for
//! for name of the event(Play), date and hall and then 
//! creates a new Play object with the given data and pushes it into the vector with plays
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


//! checks for free seats at a Play, by getting the users input for
//! for name of the event(Play), date then 
//! gets the Hall object of the Play with the same attributes and checks for the free seats there 
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

//! books a Seat at an Event, by getting the users input for
//! for name of the event(Play), date and seat number and then 
//! gets the Hall object of the Play with the same attributes and books the seat there 
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

//! unbooks a Seat at an Event, by getting the users input for
//! for name of the event(Play), date and seat number and then 
//! gets the Hall object of the Play with the same attributes and unbooks the seat there 
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

//! buys a Seat at an Event, by getting the users input for
//! for name of the event(Play), date and seat number and then 
//! gets the Hall object of the Play with the same attributes and buys the seat there 
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


//! cheks for the amount of booked seats at an event by letting the user choose 
//! whether he is going to search them by date or name or both
//! then the booked but not bought seats are displayed
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
            if (this->plays[i].getPlayName() == name && this->plays[i].getPlayDate() == date)  returnBookedSeatsHelper(i);
        }

        if (choice == 1)
        {
            if (this->plays[i].getPlayDate() == date) returnBookedSeatsHelper(i);
		}

        if (choice == 2)
        {
            if (this->plays[i].getPlayName() == name)  returnBookedSeatsHelper(i);
        }
    }
}

//! reports the total tickets bought for a period of time <from> <to> Date 
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

//! this displays the help of the program in order to guide the user
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

//! that is the menu for the program that calls different functionalities depending on the users command
void Theatre::callMenu()
{
	
	int command;
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