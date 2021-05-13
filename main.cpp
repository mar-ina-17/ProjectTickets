#include <iostream>
#include "String.h"
#include "Vector.h"
#include "Play.h"
#include "Theatre.h"
#include <ctime>
#include <cstdlib>

int main()
{    
    Theatre te = Theatre();
    te.generateHalls();
    te.addEvent();

    std::cout <<"-------------\n";
   // te.buySeat();
std::cout <<te;

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