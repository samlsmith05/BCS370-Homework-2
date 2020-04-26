//****************************************************
// File: BookCollection.h
//
// Purpose: Contains the class definition for BookCollection
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/2/19
// Description: added size, made books[] dynamically allocated
//				added a one parameter constructor, added a 
//				destructor, added a copy constructor, added an operator=, 
//				added an operator<<, added a resize, 
//				and added a createCopy
//****************************************************
#ifndef BOOKCOLLECTION_H
#define BOOKCOLLECTION_H
#include <string>
#include <iostream>
#include "Book.h"
using namespace std;

class BookCollection {
	//Member variables
private:
	Book* books;
	int size;
public:
	void Set(int index, Book b);
	Book Get(int index);
	int BookPriceCount(double lowerBound, double upperBound);
	Book CheapestBook();
	bool FindBook(string isbn, Book &b);
	double TotalPrice();
	int Size();
	void Initialize();
	string GetAuthor();

	BookCollection();
	~BookCollection();

	BookCollection(int size);
	BookCollection(const BookCollection& oldCollection);
	BookCollection& BookCollection::operator=(const BookCollection& rhs);
	friend ostream& operator<<(ostream& os, BookCollection& rhs);

	void Resize(int newSize);
	BookCollection *CreateCopy();
};

#endif

