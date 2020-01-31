
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
vector<book>bookVec;

void book::setData(string i, string n, string a, string s) // initalizes member variables to parameters.
{
	library::setID(i);
	library::setName(n);
	library::setStatus(s);
	setAuthor(a);
}

void book::setAuthor(string a) // sets authorName member variable
{
	authorName = a;
}

string book::getAuthor() // returns authorName member variable
{
	return authorName;
}

book::book() // default constructor
{
	library::library();
	authorName = "";
}

book::book(string i, string n, string a, string s) // param constructor
{
	library::setID(i);
	library::setName(n);
	library::setStatus(s);
	authorName = a;
}



void book::loadBooks() //Function to load books into the vector of book objects.
{
	book book1("1001", "The Martian", "Andy Weir", "Available");
	book book2("1002", "Lone Survivor", "Marcus Luttrell", "Available");
	book book3("1003", "The Guardians", "John Grisham", "Available");
	book book4("1004", "The Operator", "Robert O'Neil", "Available");
	book book5("1005", "Band of Brothers", "Stephen Ambrose", "Available");
	

	bookVec.push_back(book1);
	bookVec.push_back(book2);
	bookVec.push_back(book3);
	bookVec.push_back(book4);
	bookVec.push_back(book5);
}

void book::booksMenu()  // displays menu of books
{
	
	
	unsigned int i = 0;
	string input;

	for (i = 0; i < bookVec.size(); i++)
	{
		cout << bookVec[i].getID() << ", " << bookVec[i].getName() << ", " <<
			bookVec[i].getAuthor() << ", " << bookVec[i].getStatus() << endl;
		

	}

	cout << endl;
	cout << "Search for the book by entering the title or author name: ";
	cin.ignore();
	getline(cin, input); 

	
	bool found = false;
	unsigned int it = 0;

	// search book vector

	while(it < bookVec.size() && !found)
	{
		if (bookVec[it].getAuthor() == input || bookVec[it].getName() == input)
		{
			found = true;
			break;
		}
		else
			it++;

	}

	if (found)
	{
		// Print book if found
		cout << bookVec[it].getID() << ", " << bookVec[it].getName() << ", " <<
			bookVec[it].getAuthor() << ", " << bookVec[it].getStatus() << endl << endl;


		//Checkout and return prompts
		char action;
		cout << "Checkout or Return? C or R (Enter 'N' for neither.): ";
		cin >> action;

		if (action == 'C' || action == 'c')
			checkout(bookVec[it]);
		else if (action == 'R' || action == 'r')
			returnItem(bookVec[it]);
		else
			return;
		

	}
	else
		cout << "Book not found." << endl << endl;
	
}

void book::addBook() // allows user to add book
{
	book newBook;
	string bookTitle;
	string bookID;
	string bookAuthor;
	unsigned int it = 0;
	bool found = false;
	cout << endl;
	// Prompt user for new book's information
	cout << "Enter the ID of the book: ";
	cin >> bookID;
	cout << "Enter the title of the book: ";
	cin.ignore();
	getline(cin, bookTitle);
	cout << "Enter the author of the book: ";
	getline(cin, bookAuthor);
	cout << endl;
	newBook.setData(bookID, bookTitle, bookAuthor, "Available"); // creating newBook object.

	// Check to see if the book is already in the library
	while (it < bookVec.size() && !found)
	{
		if (newBook.getID() == bookVec[it].getID() || newBook.getName() == bookVec[it].getName())
		{
			found = true;
			break;
		}
		else
			it++;

	}

	if (found)
		cout << "Cannot add duplicate book." << endl << endl;
	else
	{
		
		bookVec.push_back(newBook); // add new book to vector
	}


}
