#include <string>
#include <iostream>
#include "library.h"
#include <vector>
#include <iomanip>
 
using namespace std;


library::library() // default constructor
{
	id = "";
	status = "";
	name = "";
	
}



void library::setID(string i) // sets id variable
{
	id = i;
}

void library::setName(string n) // sets name variable
{
	name = n;
}

void library::setStatus(string s) // sets status variable
{
	status = s;
}


string library::getID() // returns id variable
{
	return id;
}

string library::getName() // returns name varaible
{
	return name;
}
string library::getStatus() // returns status variable
{
	return status;
}

string library::searchLibrary() // search function for the category
{
	string cat; // category input


	
	// Prompt user for category
	cout << "Enter the category you would like to see (books, journals, or magazines): ";
	cin >> cat;
	cout << endl;
	int size = cat.size();

	for (int i = 0; i < size; i++) // Loop through cat to convert all characters to lowercase. 
	{
		cat[i] = tolower(cat[i]);
	}

	return cat;


}


void library::checkout(library& obj) // checkout function
{

	if (obj.getStatus() == "Unavailable")
		cout << "Not available for checkout." << endl << endl;
	else {
		obj.setStatus("Unavailable");
		cout << "Item successfully checked out." << endl << endl;

	}
	
	
	
}

void library::returnItem(library& obj) // return function
{

	if (obj.getStatus() == "Available")
		cout << "Item has not been checked out." << endl << endl;
	else {
	obj.setStatus("Available");
	cout << "Item sucessfully returned." << endl << endl;
	}
}

string library::addItem() // add item function
{
	library temp;
	string input;

	cout << "Would you like to add a book, journal, or magazine?: ";
	cin >> input;

	int size = input.size();
	for (int i = 0; i < size; i++) // Loop through cat to convert all characters to lowercase. 
	{
		input[i] = tolower(input[i]);
	}

	return input;


}




