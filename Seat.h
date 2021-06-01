#ifndef SEAT_H
#define SEAT_H
#include <iostream>

class Seat
{
	private:
		int seatNumber;
		bool isSeatBooked;
		bool isSeatBought;
		
		void setSeatNumber(int num);//private

	public:
		Seat();
		Seat(int num, bool status);
		Seat(const Seat&);

		int getSeatNumber() const;
		 
		bool isSeatStatBought() const;
		void buySeat();

		bool isSeatStatBooked() const;
		void bookSeat();
		void unbookSeat();	

		void print() const;

		friend std::istream& operator>>(std::istream&in, Seat& other)
		{
			std::cout <<"Set seat number: ";
			in>>other.seatNumber;
			std::cout <<"Set status (1-taken/0-free): ";
			in>>other.isSeatBooked;

			return in;
		}

		friend std::ostream& operator<<(std::ostream&out, const Seat&other)
		{
			out <<"Seat number: "<<other.seatNumber<<", Is it booked? - "<<std::boolalpha<<other.isSeatBooked<<", Is it bought? - "<<std::boolalpha<<other.isSeatBought<<std::endl;
			return out;
		}
};

Seat::Seat()
{
	this->seatNumber = 1;
	this->isSeatBooked = false;
	this->isSeatBought = false;
}

Seat::Seat(int num, bool status)
{
	this->seatNumber = num;
	this->isSeatBooked = status;
	this->isSeatBought = false;
}

Seat::Seat(const Seat& other)
{
	this->seatNumber = other.seatNumber;
	this->isSeatBooked = other.isSeatBooked;
	this->isSeatBought = other.isSeatBought;
}

int Seat::getSeatNumber() const
{
	return this->seatNumber;
}

bool Seat::isSeatStatBooked() const
{
	return this->isSeatBooked;
}

void Seat::setSeatNumber(int num)
{
	this->seatNumber = num;
}

void Seat::bookSeat()
{
	this->isSeatBooked = true;
}

void Seat::unbookSeat()
{
	this->isSeatBooked = false;
}

bool Seat::isSeatStatBought() const
{
	return this->isSeatBought;
}

void Seat::buySeat()
{
	this->isSeatBooked = true;
	this->isSeatBought = true;
	//this->code = 10101;
}

void Seat::print() const
{
	std::cout <<"Seat number: "<<this->seatNumber<<" Is it booked? - "<<std::boolalpha<<this->isSeatBooked<<std::endl;
}
#endif