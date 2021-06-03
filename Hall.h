#ifndef HALL_H
#define HALL_H
#include "Seat.h"
#include "Vector.h"
class Hall
{
	private:
		int hallNumber;
		int numberOfRows;
		int numberOfSeats;
		bool isHallBooked;
		Vector<Seat> seats;

	public:
		//mani go celiq toq hall i tresni edin vector
		Hall();
		Hall(int rows, int cols,int num);
		Hall(const Hall &);
		Hall& operator=(const Hall&);

		void bookHall();
		void unbookHall();

		int getHallNumber() const;
		int getFreeSeats() const;
		int getBookedSeats() const;
		bool getHallStatus() const;	
		Vector<Seat> addSeats(int places);

		void setHallNumber(int number);
		void buySeatInHall(int place);
		void bookSeatInHall(int place);
		void unbookSeatInHall(int place);

		void print() const;

		friend std::istream& operator>>(std::istream& in, Hall &other)
		{
			std::cout<<"Insert hall number: ";
			in>>other.hallNumber;
			std::cout<<"Insert number of rows: ";
			in>>other.numberOfRows;
			std::cout<<"Insert number of seats per row: ";
			in>>other.numberOfSeats;

			other.isHallBooked = false;

			int places = other.numberOfRows*other.numberOfSeats;

			Vector<Seat> newSeats = Vector<Seat>(places);
			
				for(int i = 0; i < places; i++)
				{
					Seat current = Seat(i+1, false);
					newSeats.push_back(current);
				}

			other.seats = newSeats;

			return in;
		}

		friend std::ostream &operator<<(std::ostream &out, const Hall &other)
		{
			out << "Hall number: "<<other.hallNumber<<std::endl;
			out << "Is hall booked: "<<std::boolalpha<<other.getHallStatus()<<std::endl;
			
			for(int i = 0; i < other.numberOfSeats*other.numberOfRows; i++)
			{
				out<<other.seats[i];
			}
			
		
			return out;
		}


};

Hall::Hall()
{
	this->hallNumber = 1000;
	this->numberOfRows = 2;
	this->numberOfSeats = 3;
	this->isHallBooked = false;
	
	int places = this->numberOfRows*this->numberOfSeats;

	this->seats = addSeats(places);
}

Hall::Hall(int rows, int cols, int num)
{
	this->hallNumber = num;
	this->numberOfRows = rows;
	this->numberOfSeats = cols;
	this->isHallBooked = false;
	
	int places = this->numberOfRows*this->numberOfSeats;

	this->seats = addSeats(places);

}

Hall::Hall(const Hall &other)
{
	this->hallNumber = other.hallNumber;
	this->numberOfRows = other.numberOfRows;
	this->numberOfSeats = other.numberOfSeats;
	this->isHallBooked = other.isHallBooked;
	this->seats = other.seats;
}

Hall& Hall::operator=(const Hall& other)
{
	if(this != &other)
	{
		this->hallNumber = other.hallNumber;
		this->numberOfRows = other.numberOfRows;
		this->numberOfSeats = other.numberOfSeats;
		this->isHallBooked = other.isHallBooked;
		this->seats = other.seats;
	}

	return *this;
}

Vector<Seat> Hall::addSeats(int places)
{
	Vector<Seat>newSeats = Vector<Seat>(places);

		for(int i = 0; i < places; i++)
		{
			Seat current = Seat(i+1, false);
			newSeats.push_back(current);
		}

	return newSeats;
}

int Hall::getHallNumber() const
{
	return this->hallNumber;
}

int Hall::getFreeSeats() const
{
	int free = 0;
	for(int i = 0; i < this->numberOfSeats*this->numberOfRows;i++)
	{
		if(!this->seats[i].isSeatStatBooked()) free++;
	}

	return free;
}

int Hall::getBookedSeats() const
{
	int booked = 0;
	for(int i = 0; i < this->numberOfSeats*this->numberOfRows;i++)
	{
		if(this->seats[i].isSeatStatBooked() && !(this->seats[i].isSeatStatBought())) booked++;
	}

	return booked;
}

bool Hall::getHallStatus() const
{
	return this->isHallBooked;
}

void Hall::bookHall()
{
	this->isHallBooked = true;
}

void Hall::unbookHall()
{
	for(int i = 0; i < this->numberOfSeats*this->numberOfRows;i++)
	{
		this->seats[i].unbookSeat();
	}
}

void Hall::setHallNumber(int number)
{
	this->hallNumber = number;
}

void Hall::bookSeatInHall(int place)
{
	if(place > 0 && place <= this->numberOfSeats*this->numberOfRows)
	{
		if(!this->seats[place-1].isSeatStatBooked())
		{
			this->seats[place-1].bookSeat();
			this->isHallBooked = true;
		}
		else
		{
			int pl;
			std::cout<<"Seat is already booked or bought, so it can't be booked again. Try again by selecting another seat or exit booking (press '0'): "<<std::endl;
			std::cin>>pl;
			if(pl == 0) exit(0);
			bookSeatInHall(pl);
		}
	}
	else
	{
		std::cout << "No such seat found."<<std::endl;
	}
}

void Hall::unbookSeatInHall(int place)
{
	if(place > 0 && place <= this->numberOfSeats*this->numberOfRows)
	{
		if(this->seats[place-1].isSeatStatBooked() && !(this->seats[place-1].isSeatStatBought()))
		{
			this->seats[place-1].unbookSeat();
		}
		else
		{
			std::cout<<"Seat is already unbooked or it is bought, so it can't be unbooked."<<std::endl;
		}
	}
	else
	{
		int pl;
		std::cout << "No such seat found. Try again by selecting another seat: "<<std::endl;
		std::cin>>pl;
		unbookSeatInHall(pl);
	}

}

void Hall::buySeatInHall(int place)
{
	if(place > 0 && place <= this->numberOfSeats*this->numberOfRows)
	{
		if(!this->seats[place-1].isSeatStatBooked())
		{
			this->seats[place-1].buySeat();
			this->isHallBooked = true;
		}
		else
		{
			int pl;
			std::cout<<"Seat is already booked or bought, so it can't be bought again. Try again by selecting another seat or exit booking (press '0'): "<<std::endl;
			std::cin>>pl;
			if(pl == 0) exit(0);
			buySeatInHall(pl);
		}
	}
	else
	{
		std::cout << "No such seat found."<<std::endl;
	}
}
void Hall::print() const
{
	std::cout << "Hall number: "<<this->hallNumber<<std::endl;
	std::cout << "Is hall booked: "<<std::boolalpha<<this->getHallStatus()<<std::endl;
	std::cout<<this->seats<<std::endl;
}

#endif



