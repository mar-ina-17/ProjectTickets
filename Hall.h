class Seat
{
	private:
		int seatNumber;
		bool seatStatus;

	public:
		Seat();
		Seat(int num, bool status);
		Seat(const Seat&);
		
		int getSeatNumber() const;
		bool getSeatStatus() const;

		void setSeatNumber(int num);
		
		Seat addSeat(const int num, const bool status);

		
		
};

class Hall
{
	private:
		int hallNumber;
		int numberOfRows;
		int numberOfSeatsPerRow;
		bool isHallBooked;
		//add Seat seats[]

	public:
		Hall();
		Hall(int num, int rows, int seats);
		Hall(const Hall &);

		int getFreeSeats() const;
		
		bool isHallBooked() const;



};