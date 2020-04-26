//****************************************************
// File: Main.cpp
//
// Purpose: Show and utilize all the functions in the Book and BookCollection classes
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/6/19
// Description: updated main
// 
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "BookCollection.h"
using namespace std;

//****************************************************
// Function: main()
//
// Purpose: entry point for the program
//
// Update Information
// ------------------
// Name: Samantha Smith
// Date: 10/6/19
// Description: added all function calls to added functions
//				in Book and BookCollection
//
//****************************************************

int main() {
	Book book1 = Book();			//calls the default constructor
	Book book2 = Book("ABC123", "The Hunger Games", 19.95);		//calls the constructor that takes all member variables
	Book book3 = Book("XYZ789", "To Kill A Mockingbird", 23.75);//calls the constructor that takes all member variables
	Book book4 = Book("JKL456", "Introduction to C++", 163.98); //calls the constructor that takes all member variables
	Book book5 = Book();			//calls the default constructor
	Book book6 = Book(book4);		//calls the copy constructor
	Book book7 = book2;				//calls operator=

	Book book8;						
	ifstream inFile;
	inFile.open("info.txt");		//opens the file
	inFile >> book8;				//calls operator>>
	inFile.close();					//closes the file

	book1.SetIsbn("321EFG");		//calls SetIsbn
	book1.SetPrice(9.99);			//calls SetPrice
	book1.SetTitle("Easy Poems");	//calls SetTitle

	cout << "Title: " << book1.GetTitle() << endl;	//calls GetTitle
	cout << "ISBN: " << book1.GetIsbn() << endl;	//calls GetIsbn
	cout << "Price: $" << book1.GetPrice() << endl;	//calls GetPrice

	cout << "\n" << book2;			//calls operator<< 
	cout << "\n" << book3;			//calls operator<<
	cout << "\n" << book4;			//calls operator<<
	cout << "\n" << book5;			//calls operator<<
	cout << "\n" << book6;			//calls operator<<
	cout << "\n" << book7;			//calls operator<<
	cout << "\n" << book8;			//calls operator<<

	book5.SetIsbn("QRS987");
	book5.SetTitle("Divergent");
	book5.SetPrice(15.99);

	cout << "------------------------------------------------------------" << endl;

	BookCollection testCollection = BookCollection();		//calls the default constructor from BookCollection


	testCollection.Set(0, book1);												//calls Set from BookCollection
	testCollection.Set(1, book2);												//calls Set from BookCollection
	testCollection.Set(2, book3);												//calls Set from BookCollection
	testCollection.Set(3, book4);												//calls Set from BookCollection
	testCollection.Set(4, book5);												//calls Set from BookCollection

	cout << "\nBooks in the BookCollection: \n" << testCollection;				//calls operator<< from BookCollection

	Book testBook = testCollection.Get(3);										//calls Get from BookCollection
	cout << "Get Test Book: \n" << testBook;									//calls operator<< to see if previous worked

	int priceRangeCount = testCollection.BookPriceCount(10.0, 20.0);			//calls BookPriceCount from BookCollection
	cout << "\nThe number of books in the price range is " << priceRangeCount << endl;

	Book cheapBook = testCollection.CheapestBook();								//calls CheapestBook from BookCollection
	cout << "\nThe cheapest book is " << cheapBook.GetTitle() << endl;

	Book resultBook = Book();
	cout << "\nFind book success: ";
	bool result = testCollection.FindBook("ABC123", resultBook);				//calls FindBook from BookCollection with a isbn that will work
	if (result == true) {
		cout << "\n" << resultBook << endl;										//prints the Book with the matching isbn
	}
	else {
		cout << "\nThat isbn was not found in the Book Collection" << endl;
	}

	cout << "Find book fail: ";
	result = testCollection.FindBook("BYU681", resultBook);						//calls FindBook from BookCollection with a isbn that will NOT work
	if (result == true) {
		cout << "\n" << resultBook << endl;										//prints the Book with the matching isbn
	}
	else {
		cout << "\nThat isbn was not found in the Book Collection" << endl;
	}

	cout << "\nThe total price of all the books is $" << testCollection.TotalPrice() << endl;	//calls TotalPrice from BookCollection
	cout << "\nThe size of the original Book Collection is " << testCollection.Size() << endl;	//calls Size from BookCollection

	BookCollection testCollection2 = BookCollection(4);											//calls BookCollection(int size)
	cout << "\nThe size of testCollection2 Book Collection is " << testCollection2.Size() << endl;//shows it created a BookCollection with the size of 4
	testCollection2 = BookCollection(testCollection);											//calls the copy constructor from BookCollection
	cout << "\nBooks in the copy constructed BookCollection: \n" << testCollection2;

	BookCollection testCollection3 = BookCollection();
	testCollection3 = testCollection;															//calls operator= from BookCollection
	cout << "\nBooks in the operator= BookCollection: \n" << testCollection3;
	
	testCollection3.Resize(6);																	//calls Resize
	cout << "\nBooks in the testCollection3 BookCollection after larger resize: \n" << testCollection3;

	testCollection3.Resize(4);																	//calls Resize
	cout << "\nBooks in the testCollection3 BookCollection after smaller resize: \n" << testCollection3;

	cout << "\nThe author of this project is " << testCollection.GetAuthor() << endl;			//calls GetAuthor from BookCollection

	BookCollection *p;																			//creates a pointer for CreateCopy to return to
	p = testCollection.CreateCopy();															//calls CreateCopy

	cout << "The collection after CreateCopy() is: \n" << *p;

	delete p;																					//deletes the pointer returned from CreateCopy

	testCollection.Initialize();																//calls Initialize from BookCollection

	return 0;
}