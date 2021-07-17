#include<bits/stdc++.h>
using namespace std;




// actors
//  - customer
//  - system

// use cases 
//  - list all cities where cinemas are located 
//  - search by parameter
//  - select a show 
//  - book tickets
//  - select multiple seats

class BMSService {
	vector<CinemaHall> cinemas;
public:
	vector<Movie> getMovies(Date date, String city);
	vector<CinemaHall> getCinemaHalls(string city);
};


class CinemaHall {
public:
	int CinemaHallId;
	string cinemaHallName;
	Address address;
	vector<Audi> audiList;

	map<Date, Movie> getMovies(vector<Date> dateList);
	map<Date, Show> getShows(vector<Date> dateList);
};


class Audi {
public:
	int audiId;
	string audiNAme;
	int totalSeats;
	vector<Show> shows;
};



class Show {
public:
	int showId;
	Movie movie;
	Date startTime;
	Date endTime;

	CinemaHall cinemaPlayedAt;
	vector<Seat> seats;
};


class Seat {
public:
	int seatId;
	SeatType seatType;
	SeatStatus seatStatus;
	double price;
};


enum SeatType {
	DELUX, VIP, ECONOMY, OTHER
};

enum SeatStatus {
	BOOKED, AVAILABLE, RESERVED, NOT_AVAILABLE
};


class Movie {
public:
	string movieName;
	int id;
	int durationINMins;
	string language;
	Genre genre; // which type of movie is romantic/action
	Date releaseDate;
	map<string, vector<Show>> cityShowMap;
};


enum Genre {
	SCI_FI, DRAMA, ROM_COM, FANTASY
};



class User {
public:
	int userId;
	Search searchObj;
};


class SystemMember: public User {
	Account account;
	string name;
	string email;
	Address address;
};



class Member: public SystemMember {
public:
	Booking makeBooking(Booking booking);
	vector<Booking> getBooking();
};


class Admin: public SystemMember {
public:
	bool addMovie(Movie movie);
	bool addShow(Show show);
};


class Account {
public:
	string userName;
	string password;
};



class Search {
public:
	vector<Movie> searchMoviesByName(string name);
	vector<Movie> searchMoviesByGenre(Genre genre);
	vectror<Movie> searchMoviesByLanguage(string language);
	vector<Movie> searchMoviesByDate(Date releaseDate);
};


class Booking {
	string bookingId;
	Date bookingDate;
	Memeber member;
	Show show;
	Audi audi;
	BookingStatus bookingStatus;
	double totalAmount;
	vector<Seat> seats;
	Payment paymentObj;

	bool makePayment(Payment payment);
};



enum BookingStatus {
	REQUESTED, PENDING, CONFIRMED, CANCELLED
};


class Payment {
public:
	double amount;
	Date paymentDate;
	int transactionId;
	PaymentStatus paymentStatus;
};




enum PaymentStatus {
	UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED
};






















int32_t main(){

}