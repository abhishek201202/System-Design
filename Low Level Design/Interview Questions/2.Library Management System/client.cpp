#include<bits/stdc++.h>
using namespace std;


class Library{
	string name;
	Address location;
	vector<BookItem> books;
};


class Address{
	int pinCode; // zipCode
	string street, city, state, country;
};


class Book{
	string uniqueId;
	string title;
	vector<Author> authors;
	BookType bookType;
};

class BookItem: public Book{
	string barcode;
	Date publicationDate;
	Rack rackLocation;
	BookStatus bookStatus;
	BookFormat bookFormat;
	Date issueDate;
};



enum BookType{
	SCI_FI, ROMANTIC, FANTASY, DRAMA
};

enum BookFormat{
	HARDCOVER, PAPERBACK, NEWSPAPER, JOURNAL
};

enum BookStatus{
	ISSUED, AVAILABLE, RESERVED, LOST
};


class Rack{
	int number;
	string locationId;
};


/*******************************************************
Defining Actors
*******************************************************/


class Person{
	string firstName;
	string lastName;
};

class Author: public Person{
	vector<Book> booksPublished;
};



class SystemUsers: public Person{
	string Email, phoneNumber;
	Account account;
};


class Member: public SystemUsers{
	int totalBookCheckedOut;
	Search searchObj;
	BookIssueService issueService;
};

class Librarian: public SystemUsers{
	Search searchObj;
	BookIssueService issueServices;
public:
	void addBookItem(BookItem bookItem);
	void deleteBookItem(string barcode);
	void editBookItem(BookItem bookItem);
};


class Account{
	string userName;
	string password;
	int accountId;
};





class Search {
public:
	vector<BookItem> getBookByTitle(string title);
	vector<BookItem> getBookByAuthor(Author author);
	vector<BookItem> getBookByType(BookType bookType);
	vector<BookItem> getBookByPublicationDate(date publicationDate);
};



class BookIssuesService {
	FineService fineService;
public:
	void updateReservationDetail(BookReservationDetail bookReservationDetail);
	BookReservationDetail reserveBook(BookItem book, SystemUsers user);
	BookIssueDetail issueBook(BookItem book, SystemUsers user);
	BookIssueDetail renewBook(BookItem book, SystemUsers user);
	void returnBook(BookItem book, SystemUsers user);
};


class BookLending {
	BookItem book;
	Date startDate;
	SystemUsers user;
};


class BookReservationDetail: public BookLending {
	ReservationStatus reservationStatus;
};

class BookIssueDetail: public BookLending {
	Date dueDate;
};

class FineService {
public:
	Fine calculateFine(BookItem book, SystemUsers user, int days);
};

class Fine {
	Date fineDate;
	BookItem book;
	SystemUsers user;
	double fineValue;
};




int32_t main(){

}