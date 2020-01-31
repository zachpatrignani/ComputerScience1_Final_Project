#include "journal.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

vector<journal>journalVec; // vector of journal objects

void journal::setData(string i, string n, string v, string s) // initialzes member variables to parameters
{
	library::setID(i);
	library::setName(n);
	library::setStatus(s);
	setVolume(v);
}

void journal::setVolume(string v) // sets volume member variable
{
	volume = v;
}

string journal::getVolume() // returns volume member variable
{
	return volume;
}

journal::journal() // default constructor
{
	library::library();
	volume = "";
}

journal::journal(string i, string n, string v, string s) // param. constructor
{
	library::setID(i);
	library::setName(n);
	library::setStatus(s);
	volume = v;
}



void journal::loadJournals() //Function to load journals into the vector of journals objects.
{
	journal j1("2000", "Journal of Cryptology", "1", "Available");
	journal j2("2001", "American Dental Association", "4", "Available");
	journal j3("2002", "Impossible Engineering", "2", "Available");
	journal j4("2003", "Journal of Radiology", "6", "Available");
	journal j5("2004", "Gamespot", "8", "Available");


	journalVec.push_back(j1);
	journalVec.push_back(j2);
	journalVec.push_back(j3);
	journalVec.push_back(j4);
	journalVec.push_back(j5);
	

}

void journal::journalsMenu() // displays journals
{
	unsigned int i = 0;

	for (i = 0; i < journalVec.size(); i++) // Prints journals
	{
		cout << journalVec[i].getID() << ", " << journalVec[i].getName() << ", " <<
			journalVec[i].getVolume() << ", " << journalVec[i].getStatus() << endl;


	}
	
	cout << endl;
	string input;
	cout << "Search for the journal by title or volume: ";
	cin.ignore();
	getline(cin, input);

	//search the journal vector 
	unsigned int it = 0;
	bool found = false;


	while (it < journalVec.size() && !found)
	{
		if (journalVec[it].getVolume() == input || journalVec[it].getName() == input)
		{
			found = true;
			break;
		}
		else
			it++;

	}

	if (found)
	{

		//Print journal object if it is found
		cout << journalVec[it].getID() << ", " << journalVec[it].getName() <<
			", " << journalVec[it].getVolume() << ", " << journalVec[it].getStatus() << endl << endl;


		//Checkout and return prompts
		char action;
		cout << "Checkout or Return? C or R (Enter 'N' for neither.): ";
		cin >> action;

		if (action == 'C' || action == 'c')
		{
			checkout(journalVec[it]);

		}

		else if (action == 'R' || action == 'r')
		{
			returnItem(journalVec[it]);

		}
		else
		{
			return;
		}
	}
	else
		cout << "Journal not found." << endl << endl;


}

void journal::addJournal() // Adds new journal
{
	journal newJournal;
	string journalTitle;
	string journalID;
	string journalVolume;
	unsigned int it = 0;
	bool found = false;

	//Prompt user for new journal info
	cout << "Enter the ID of the journal: ";
	cin >> journalID;
	cout << "Enter the title of the journal: ";
	getline(cin, journalTitle);
	cout << "Enter the volume of the journal: ";
	getline(cin, journalVolume);

	newJournal.setData(journalID, journalTitle, journalVolume, "Available"); // creating newJournal object.
	
	// Check to see if the journal is already in the library
	while (it < journalVec.size() && !found)
	{
		if (newJournal.getID() == journalVec[it].getID() || newJournal.getName() == journalVec[it].getName())
		{
			found = true;
			break;
		}
		else
			it++;

	}

	if (found)
		cout << "Cannot add duplicate journal." << endl << endl;
	else
		journalVec.push_back(newJournal); // add new journal to journal vector

}