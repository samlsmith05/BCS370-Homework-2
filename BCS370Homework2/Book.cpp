//****************************************************
// File: Book.cpp
//
// Purpose: Contains all of the function definitions 
//			for the Book class
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Made all member variables pointers and 
//				changed all functions accordingly, 
//				added a destructor and an operator>>
//*****************************************************
#include "Book.h"

//****************************************************
// Function: Book()
//
// Purpose: The default constructor for Book
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Updated the code since all member variables 
//				are now pointers and allocated dynamic memory
//****************************************************
Book::Book() {
	//allocates the memory for the pointer variables
	isbn = new string;
	title = new string;
	price = new double;

	//sets the default values
	*isbn = "NO ISBN";
	*title = "NO TITLE";
	*price = 0.0;
}

//****************************************************
// Function: GetIsbn()
//
// Purpose: gets the isbn number of the book and returns it
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced isbn
//****************************************************
string Book::GetIsbn() {
	return *isbn;
}

//****************************************************
// Function: GetTitle()
//
// Purpose: gets the title of the book and returns it
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced title
//****************************************************
string Book::GetTitle() {
	return *title;
}

//****************************************************
// Function: GetPrice()
//
// Purpose: gets the price of the book and returns it
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced price
//****************************************************
double Book::GetPrice() {
	return *price;
}

//****************************************************
// Function: SetIsbn(string i)
//
// Purpose: sets the isbn of the book
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced isbn
//****************************************************
void Book::SetIsbn(string i) {
	*isbn = i;
}

//****************************************************
// Function: SetTitle(string t)
//
// Purpose: sets the title of the book
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced title
//****************************************************
void Book::SetTitle(string t) {
	*title = t;
}

//****************************************************
// Function: SetPrice(double p)
//
// Purpose: sets the price of the book
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced price
//****************************************************
void Book::SetPrice(double p) {
	*price = p;
}

//****************************************************
// Function: Book(string isbn, string title, double price)
//
// Purpose: A constructor with all member variables for Book
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Allocated dynamic memory for the pointers
//				and derefrenced the variables
//****************************************************
Book::Book(string i, string t, double p) {
	//allocates the memory for the pointer variables
	isbn = new string;
	title = new string;
	price = new double;
	//sets the values of Book with the ones sent in as parameters
	*isbn = i;
	*title = t;
	*price = p;
}

//****************************************************
// Function: Book(const Book& oldBook)
//
// Purpose: does a deep copy of the member variables 
//			as a copy constuctor
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced all variables in order to 
//				copy all of the data over not the addresses
//****************************************************
Book::Book(const Book& oldBook) {
	//creates dynamically allocated memory
	isbn = new string;
	title = new string;
	price = new double;
	//copies the information of oldBook into a new Book
	*isbn = *oldBook.isbn;
	*title = *oldBook.title;
	*price = *oldBook.price;
}

//***************************************************
// Function: operator=(const Book& rhs)
//
// Purpose: overloads the assignment operator = and 
//			creates an object like a copy constructor
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced all variables in order to 
//				copy all of the data over not the addresses
//****************************************************
Book& Book::operator=(const Book& rhs) {
	//checks to see if they are already equal
	if (this == &rhs) {
		return *this;
	}
	//sets the current instance of Book's values to the same value as rhs Book instance
	*isbn = *rhs.isbn;
	*title = *rhs.title;
	*price = *rhs.price;
	return *this;		//returns the current instance of Book
}

//****************************************************
// Function: operator<<(ostream& os, Book& rhs)
//
// Purpose: prints the values of all member variables 
//			on the given ostream
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: Derefrenced all member variables in order to 
//				get all the data for the ostream
//****************************************************
ostream& operator<<(ostream& os, Book& rhs) {
	os << "Title: " << *rhs.title << "\nISBN: " << *rhs.isbn << "\nPrice: $" << *rhs.price << endl;
	return os;		//returns the os so it will print the entire line above
}

//****************************************************
// Function: operator>>(istream& is, Book& rhs)
//
// Purpose: reads the values of all member variables 
//			from the given istream
//
// Update Information
// ------------------
// 
//****************************************************
istream& operator>>(istream& is, Book& rhs) {
	is >> *rhs.title >> *rhs.isbn >> *rhs.price;
	return is;
}

//****************************************************
// Function: ~Book()
//
// Purpose: Destructor for Book
//
// Update Information
// ------------------
// 
//****************************************************
Book::~Book() {
	delete isbn;
	delete price;
	delete title;
	cout << "Book Destructor called..." << endl;
}