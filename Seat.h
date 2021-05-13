#ifndef SEAT_H
#define SEAT_H
#include <iostream>
#include <ostream>
#include "String.h"

class Seat
{
	private:
		int seatNumber;
		bool isSeatBooked;
		bool isSeatBought;
		//size_t code;
		//String note;

	public:
		Seat();
		Seat(int num, bool status);//,const char*code,const char* note);
		Seat(const Seat&);
		Seat& operator=(const Seat&);
		
		int getSeatNumber() const;
		size_t getSeatCode() const;
		//String getSeatNote() const;
		void setSeatCode(size_t code);
		//void setSeatNote(String note);

		bool isSeatStatBooked() const;
		bool isSeatStatBought() const;

		void setSeatNumber(int num);
		void buySeat();
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
			std::cout <<"Seat number: "<<other.seatNumber<<" Is it booked? - "<<std::boolalpha<<other.isSeatBooked<<" Is it bought? - "<<std::boolalpha<<other.isSeatBought<<std::endl;
			//std::cout <<"Code: "<<other.code<<std::endl;
			//" Note: "<<other.note<<std::endl;
			return out;
		}
};

Seat::Seat()
{
	this->seatNumber = 1;
	this->isSeatBooked = false;
	this->isSeatBought = false;
	//this->code = 100000;
	//this->note = String("testNote");
}

Seat::Seat(int num, bool status)//const char*code,const char* note)
{
	this->seatNumber = num;
	this->isSeatBooked = status;
	//this->note = String(note);
}

Seat::Seat(const Seat& other)
{
	this->seatNumber = other.seatNumber;
	this->isSeatBooked = other.isSeatBooked;
	this->isSeatBought = other.isSeatBought;
	//this->code = other.code;
	//this->note = other.note;
}

Seat& Seat::operator=(const Seat& other)
{
	if(this != &other)
	{
		this->seatNumber = other.seatNumber;
		this->isSeatBooked = other.isSeatBooked;
		this->isSeatBought = other.isSeatBought;
		//this->code = other.code;
		//this->note = other.note;
	}
	return *this;
}
int Seat::getSeatNumber() const
{
	return this->seatNumber;
}

bool Seat::isSeatStatBooked() const
{
	return this->isSeatBooked;
}
bool Seat::isSeatStatBought() const
{
	return this->isSeatBought;
}

void Seat::setSeatNumber(int num)
{
	this->seatNumber = num;
}

void Seat::buySeat()
{
	this->isSeatBooked = true;
	this->isSeatBought = true;
}

void Seat::bookSeat()
{
	this->isSeatBooked = true;
}

void Seat::unbookSeat()
{
	this->isSeatBooked = false;
}

/*size_t Seat::getSeatCode() const
{
	return this->code;
}

void Seat::setSeatCode(size_t code)
{
	this->code = code;
}

String Seat::getSeatNote() const
{
	return this->note;
}

void Seat::setSeatNote(String note)
{
	this->note = note;
}
*/
void Seat::print() const
{
	std::cout <<"Seat number: "<<this->seatNumber<<" Is it booked? - "<<std::boolalpha<<this->isSeatBooked<<std::endl;
}
#endif