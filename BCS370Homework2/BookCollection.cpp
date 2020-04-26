//****************************************************
// File: BookCollection.cpp
//
// Purpose: Contains all of the function definitions 
//			for the BookCollection class
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed all looping conditions to size,
//				dynamically allocated the array, added a 
//				destructor, added a one parameter constructor, 
//				added a copy constructor, added an operator=, 
//				added an operator<<, added a resize, 
//				and added a createCopy
//				
//*****************************************************
#include "BookCollection.h"
#include <iostream>


//****************************************************
// Function: Set(int index, Book b)
//
// Purpose: Sets array elements with the Books
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
void BookCollection::Set(int index, Book b) {
	//checks if the index given is a valid index
	//if it is, it saves it to the array element
	if (index < size && index >= 0) {
		books[index] = b;
	}

	//otherwise, it prints to the user that the index is not valid
	else
	{
		cout << "That was not a valid index." << endl;
	}

}

//****************************************************
// Function: Get(int index)
//
// Purpose: Returns the Book information at the index given
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
Book BookCollection::Get(int index) {
	//checks if the index given is a valid index
	//if it is, it returns the book at the element of the array
	if (index < size && index >= 0) {
		return books[index];
	}

	//otherwise, it prints to the user that the index is not valid
	else
	{
		cout << "That was not a valid index." << endl;
	}
}

//****************************************************
// Function: BookPriceCount(double lowerBound, double upperBound)
//
// Purpose: returns the total number of books within the price bounds
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
int BookCollection::BookPriceCount(double lowerBound, double upperBound) {
	int count = 0;		//the number of books between the bounds

						//loops through the array books 
	for (int i = 0; i < size; i++) {
		//adds one to count if the price of the book is between the bounds
		if (books[i].GetPrice() >= lowerBound && books[i].GetPrice() <= upperBound) {
			count += 1;
		}
	}
	return count;
}

//****************************************************
// Function: CheapestBook()
//
// Purpose: returns the book with the lowest price
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
Book BookCollection::CheapestBook() {
	Book cheapest;			//the cheapest book in the array
	cheapest = books[0];	//initialize the cheapeast book for comparison

							//loops through the array books 
	for (int i = 0; i < size; i++) {
		//checks to see which book is cheaper
		//if the index book is cheaper, it saves that book to cheapest
		if (books[i].GetPrice() < cheapest.GetPrice()) {
			cheapest = books[i];
		}
	}

	return cheapest;
}

//****************************************************
// Function: FindBook(string isbn, Book &b)
//
// Purpose: finds if the book sent in is in the 
//			array books and returns either true or false
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
bool BookCollection::FindBook(string isbn, Book &b) {
	//loops through all the elements of the array
	for (int i = 0; i < size; i++) {

		string currentisbn = books[i].GetIsbn();		//sets the current isbn for comparison
		int compareResult = currentisbn.compare(isbn);	//result of the comparison between the isbn's


		if (compareResult == 0) {			//if the currentisbn and isbn passed in are equal it sets the current book as the book passed by reference and it returns true
			b = books[i];
			return true;
		}
	}

	return false;					//if the isbn is not in any of the books of BookCollection, it will return false

}

//****************************************************
// Function: TotalPrice()
//
// Purpose: totals the price of all the books in the array books
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
double BookCollection::TotalPrice() {
	double total;		//the total price of all the books 
	total = 0.0;		//initialize total

						//loops through all the elements of the array
	for (int i = 0; i < size; i++) {
		//adds the current index book price to the total
		total = total + books[i].GetPrice();
	}

	return total;
}

//****************************************************
// Function: Size()
//
// Purpose: returns the size of the array
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the return to variable size 
//****************************************************
int BookCollection::Size() {
	return size;
}

//****************************************************
// Function: Initialize()
//
// Purpose: sets all the elements of the array to default values
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	changed the looping condition to size 
//****************************************************
void BookCollection::Initialize() {
	//loops through the array books
	for (int i = 0; i < size; i++) {
		//sets each element of books with the default constructor Book()
		books[i] = Book();
	}
}

//****************************************************
// Function: GetAuthor()
//
// Purpose: returns my name
//
// Update Information
// ------------------
//
//****************************************************
string BookCollection::GetAuthor() {
	return "Samantha Smith";
}

//****************************************************
// Function: BookCollection()
//
// Purpose: default constructor for BookCollection
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description:	dynamically allocted the array and changed 
//				the size to the variable size
//****************************************************
BookCollection::BookCollection() {
	//dynamically allocates the array
	size = 5;
	books = new Book[size];
	//sets the default values by calling on the Initialize() function
	Initialize();
}

//****************************************************
// Function: ~BookCollection()
//
// Purpose: Destructor for Book
//
// Update Information
// ------------------
// 
//****************************************************
BookCollection::~BookCollection() {
	delete[] books;		//deletes all the elements of the array
	cout << "BookCollection Destructor called..." << endl;
}

//****************************************************
// Function: BookCollection(int s)
//
// Purpose: one parameter constructor for BookCollection
//			that takes in the size of the array
//
// Update Information
// ------------------
// 
//****************************************************
BookCollection::BookCollection(int s) {
	//dynamically allocates the array
	books = new Book[s];
	size = s;
	//sets the default values by calling on the Initialize() function
	Initialize();
}

//****************************************************
// Function: BookCollection(const BookCollection& oldCollection)
//
// Purpose: does a deep copy of the member variables 
//			as a copy constuctor
//
// Update Information
// ------------------
// 
//****************************************************
BookCollection::BookCollection(const BookCollection& oldCollection) {
	//creates a new dynamically allocated array
	books = new Book[oldCollection.size];
	//sets the size equal to the oldCollection's
	size = oldCollection.size;	

	//copies the information of oldCollection into a new Collection
	for (int i = 0; i < oldCollection.size; i++) {
		books[i] = oldCollection.books[i];
	}
}

//***************************************************
// Function: operator=(const BookCollection& rhs)
//
// Purpose: overloads the assignment operator = and 
//			creates an object like a copy constructor
//
// Update Information
// ------------------
// 
//****************************************************
BookCollection& BookCollection::operator=(const BookCollection& rhs) {
	//checks to see if you are assigning to the same collection
	if (this == &rhs) {
		return *this;
	}

	delete[] books;					//delete the books collection 
	books = new Book[rhs.size];		//creates a new dynamically allocated collection of rhs's size
	size = rhs.size;				//sets the size equal
	//sets the current instance of Book's values to the same value as rhs Book instance
	//copies the information of oldCollection into a new Collection
	for (int i = 0; i < rhs.size; i++) {
		books[i] = rhs.books[i];
	}
	return *this;		//returns the current instance of Book
}

//****************************************************
// Function: operator<<(ostream& os, BookCollection& rhs)
//
// Purpose: prints the values of all member variables 
//			on the given ostream
//
// Update Information
// ------------------
// 
//****************************************************
ostream& operator<<(ostream& os, BookCollection& rhs) {
	for (int i = 0; i < rhs.size; i++) {
		os << "Book " << i+1 << ": \n" << rhs.books[i] << "\n";
	}
	return os;		//returns the os so it will print the entire line above
}

//****************************************************
// Function: Resize(int newSize)
//
// Purpose: resizes the array to a smaller or larger size
//
// Update Information
// ------------------
// 
//****************************************************
void BookCollection::Resize(int newSize) {
	//creates a new dynamically allocated array
	Book* temp = new Book[newSize];
	
	//enters this option if size is greater than newSize
	if (newSize < size) {
		//loops through to put each value of books into the temp array
		for (int i = 0; i < newSize; i++) {
			temp[i] = books[i];
		}
	}
	//enters this option if newSize is larger than size
	if (newSize > size) {
		//loops through to put each value of books into the temp array
		for (int i = 0; i < size; i++) {
			temp[i] = books[i];
		}
		//loops through to put default Book constructor into the index of the temp array
		for (int i = 0; i < (newSize - size); i++) {
			temp[size+i] = Book();

		}
	}

	delete[] books;	
	//makes books equal to the temp array
	books = temp;
	size = newSize;	//sets the size equal to the newSize
}

//****************************************************
// Function: CreateCopy()
//
// Purpose: creates a deep copy of the current instance
//			and returns the pointer
//
// Update Information
// ------------------
// 
//****************************************************
BookCollection* BookCollection::CreateCopy() {
	//creates new dynamically allocated array
	BookCollection* newCollection = new BookCollection();

	//copies the values using operator=
	*newCollection = *this;
	
	return newCollection;
}


