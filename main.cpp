#include <iostream>
#include "Vector.h"
#include "Theatre.h"

int main()
{    
    Theatre te = Theatre();
    
    te.generateHalls();
    //
    te.addEvent();
    std::cout <<"-------------\n";
    te.buySeat();
    //te.bookSeat();
    std::cout <<"-------------\n";
    /*te.freeSeats();
    std::cout <<"-------------\n";
    te.unbookSeat();*/
    std::cout <<te;
    //te.buySeat();
    //

    /*//
    //std::cout <<"-------------\n";
    //te.freeSeats();
    //std::cout <<te;
    //te.unbookSeat();
    std::cout <<"-------------\n";
    te.freeSeats(); */

   // Hall s = Hall();
   // Seat s1 = Seat(12, true, "hdshdd", "hjsd");
    //s1 = Seat(s);

   // s = s1;
   // std::cout <<s;

    return 0;
}