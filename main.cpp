#include <iostream>
//#include "Vector.h"
#include "Theatre.h"
//#include "Play.h"
void displayHelp()
{
    std::cout <<"0 - exit program" << std::endl;
    std::cout <<"1 - addevent <date> <name> <hall> -- Adds a new event of date <date> named <name> in the <hall> hall.\n";
    std::cout <<"2 - freeseats <date> <name> -- Displays a free space for a performance named <name> on <date> (unsold and unsaved tickets).\n";
    std::cout <<"3 - book <seat> <date> <name> -- Saves a show ticket named <name> to <date> on line <row> and place <seat>.\n";
    std::cout <<"4 - unbook <seat> <date> <name> -- Cancel a reservation for a show named <name> on <date> on line <row> and place <seat>.\n";
    std::cout <<"5 - buy <seat> <date> <name> -- Purchases a ticket for a show named <name> on <date> at <seat>.\n";
    std::cout <<"6 - bookings [<date>] [<name>] -- Displays saved but unpaid (unpurchased) performance tickets named <name> on <date>. If <name> is omitted, displays information about all performances on the given date. If <date> is omitted, displays information about all dates.\n";
    std::cout <<"7 - help\n";
}

int main()
{    
     Theatre te;
   	te.generateHalls(4);
	std::cout<<te;
/*
displayHelp();
size_t command;
std::cin>>command;
    while(command != 0)
    {
        if(command == 1)
        {
            std::cout <<"You can now add an event:\n";
            te.addEvent();
            std::cout <<te;
            std::cout <<"Input command: ";
            std::cin>>command;
        }

        if(command == 2)
        {
            std::cout <<"You can now check for free seats at an event:\n";
            te.freeSeats();
            std::cout <<te;
            std::cout <<"Input command: ";
            std::cin>>command;
        }

        if(command == 3)
        {
            std::cout <<"You can now book a seat at an event:\n";
            te.bookSeat();            
            std::cout <<te;            
            std::cout <<"Input command: ";
            std::cin>>command;
        } 

        if(command == 4) 
        {
            std::cout <<"You can now unbook a seat at an event:\n";
            te.unbookSeat();
            std::cout <<te;
            std::cout <<"Input command: ";
            std::cin>>command;
        }

        if(command == 5) 
        {
            std::cout <<"You can now buy a seat at an event:\n";
            te.buySeatForEvent();
            std::cout <<te;
            std::cout <<"Input command: ";
            std::cin>>command;
        }
        if(command == 6)
        {
            std::cout <<"You can now see the amount of booked seats at an event:\n";
            te.bookedSeatsReport();
            std::cout <<"Input command: ";
            std::cin>>command;
        } 
        if(command == 7)
        {
            displayHelp();
            std::cout <<"Input command: ";
            std::cin>>command;
        } 
    }
/**/

  /*  Date date;
    std::cin>>date;
    std::cout<<date;


	Play s;
	std::cin>>s;
	std::cout<<s;*/

    return 0;
}
