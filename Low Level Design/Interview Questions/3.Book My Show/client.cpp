#include<bits/stdc++.h>
using namespace std;

/*

Movie
----------------
int id;
string name;
double duration;

MovieController
----------------
map<City, vector<int>> cityMovieIds;
vector<Movie> movies;
getMoviesByCity(string cityName);


Theatre
----------------
int id;
Address address;
vector<Screen> screens;
vector<Show> shows;

Show
----------------
int id;
int movieId;
int screenId;
int startTime;
vector<int> bookedSeatIds;

Screen
----------------
int id;
vector<Seat> seats;

Seat
----------------
int id;
int row;
SeatCategory category;

enum SeatCategory {
	SILVER, GOLD, PLATINUM
};

Booking
----------------
int id;
int showId;
vector<int> seatIds;
int paymentId;

Payment
----------------
int id;
PaymentStatus status;
PaymentStrategy strategy;

PaymentStrategy (CreditCard, DebitCard)
----------------
makePayment();


TheatreController
----------------
map<City, vector<int>> cityTheatreIds;
getTheatreByCity(int cityId)
getShowByMovieId(int movieId)
getAvailableSeatsByShowId(int showId)
bookSeats(int showId, vector<int> seatIds)


BookMyShow
----------------
MovieController *movieController;
TheatreController *theatreContrller;

Locking Mechanism - 
We will go with optimistic locking mechanism and use redis for locking 

*/
