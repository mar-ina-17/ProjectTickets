class Seat
{
	private:
		char* seatNumber;
		bool seatStatus;

	public:
		Seat();
		Seat(char* num, bool status);
		Seat(const Seat&);
		
		int getSeatNumber() const;
		bool getSeatStatus() const;

		void setSeatNumber(char* num);
		
		Seat addSeat(const char* num, const bool status);		
};

class Hall
{
	private:
		int hallNumber;
		int numberOfRows;
		bool isHallBooked;
		Seat* seats;

	public:
		Hall();
		Hall(int num, int rows, Seat* seats);
		Hall(const Hall &);

		int getFreeSeats() const;
		
		bool isHallBooked() const;
};