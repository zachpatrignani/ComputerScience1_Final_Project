#include "magazine.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
vector<magazine>magVec; // vector of magazine objects


void magazine::setData(string i, string n, string is, string s) // initializes member variables
{
	library::setID(i);
	library::setName(n);
	library::setStatus(s);
	setIssue(is);
}

void magazine::setIssue(string is) // set issue variable
{
	issue = is;
}

string magazine::getIssue() // return issue variable
{
	return issue;
}

magazine::magazine() // default constructor
{
	library::library();
	issue = "";
}

magazine::magazine(string i, string n, string is, string s) // param. constructor
{
	library::setID(i);
	library::setName(n);
	library::setStatus(s);
	issue = is;
}



void magazine::loadMagazines() //Function to load magazines into the vector of magazine objects.
{
	magazine mag1("3001", "Sports Illustrated", "1", "Available");
	magazine mag2("3002", "ESPN Magazine", "1", "Available");
	magazine mag3("3003", "National Geographic", "1", "Available");
	magazine mag4("3004", "Science", "1", "Available");
	magazine mag5("3005", "NewsWeek", "1", "Available");


	magVec.push_back(mag1);
	magVec.push_back(mag2);
	magVec.push_back(mag3);
	magVec.push_back(mag4);
	magVec.push_back(mag5);

}

void magazine::magazinesMenu() // displays magazines
{
	unsigned int i = 0;

	for (i = 0; i < magVec.size(); i++)
	{
		cout << magVec[i].getID() << ", " << magVec[i].getName() << ", " <<
			magVec[i].getIssue() << ", " << magVec[i].getStatus() << endl;
	}

	cout << endl;
	string input;
	cout << "Search for the magazine by entering the title or issue: ";
	cin.ignore();
	getline(cin, input); 
	
	//Linear Search

	unsigned int it = 0;
	bool found = false;

	while (it < magVec.size() && !found)
	{
		if (magVec[it].getIssue() == input || magVec[it].getName() == input)
		{
			found = true;
			break;
		}
		else
			it++;

	}

	if (found)
	{

		cout << magVec[it].getID() << ", " << magVec[it].getName() << ", " <<
			magVec[it].getIssue() << ", " << magVec[it].getStatus() << endl;
		cout << endl;
		//Checkout and return prompts
		char action;
		cout << "Checkout or Return? C or R (Enter 'N' for neither.): ";
		cin >> action;

		if (action == 'C' || action == 'c')
			checkout(magVec[it]);
		else if (action == 'R' || action == 'r')
			returnItem(magVec[it]);
		else
			return;

	}
	else
		cout << "Magazine not found." << endl;

}

void magazine::addMagazine() // function to add a new magazine
{
	magazine newMag;
	string magTitle;
	string magID;
	string magIssue;
	unsigned int it = 0;
	bool found = false;

	// Prompt user for new magazine data
	cout << "Enter the ID of the magazine: ";
	cin >> magID;
	cout << "Enter the title of the magazine: ";
	getline(cin, magTitle);
	cout << "Enter the author of the magazine: ";
	getline(cin, magIssue);

	newMag.setData(magID, magTitle, magIssue, "Available"); // creates newMag object
	

	while (it < magVec.size() && !found) // Checks that the new magazine doesn't already exist
	{
		if (newMag.getID() == magVec[it].getID() || newMag.getName() == magVec[it].getName())
		{
			found = true;
			break;
		}
		else
			it++;

	}

	if (found)
		cout << "Cannot add duplicate magazine.";
	else
		magVec.push_back(newMag); // add newMag to magVec


}