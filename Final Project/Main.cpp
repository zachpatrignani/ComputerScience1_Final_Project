
#include <conio.h> // For function getch()
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "Book.h"
#include "journal.h"
#include "magazine.h"
#include "library.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"




void searchChoice(string input)
{
	library libItem;
	book tempBook;
	journal tempJournal;
	magazine tempMagazine;
	

	input = libItem.searchLibrary();
	if (input == "books")
		tempBook.booksMenu();
	else if (input == "journals")
		tempJournal.journalsMenu();
	else if (input == "magazines")
		tempMagazine.magazinesMenu();
	else
		cout << input << endl;

}


void libraryMenu() //Display menu
{
	cout << "1. Search Catalog" << endl;
	cout << "2. Check out" << endl;
	cout << "3. Return" << endl;
	cout << "4. Add a new item" << endl;
	cout << "5. Exit" << endl;
}

void runlibrary()
{
	string input;
	string str = "";
	char choice = 0;
	library libItem;
	book tempBook;
	journal tempJournal;
	magazine tempMagazine;
	tempBook.loadBooks();
	tempJournal.loadJournals();
	tempMagazine.loadMagazines();
	

	while (true)
	{
		try
		{
			libraryMenu();
			cout << "\nPlease select: ";
			cin >> choice;
			getline(cin, str);

			switch (choice)
			{
			case '1':
				searchChoice(input);
				break;
			case '2':
				searchChoice(input);
				break;
			case '3':
				searchChoice(input);
				break;
			case '4':
				input = libItem.addItem();
				if (input == "book")
					tempBook.addBook();
				else if (input == "journal")
					tempJournal.addJournal();
				else if (input == "magazine")
					tempMagazine.addMagazine();
				break;
			case '5':
				return;
			default:
				cout << "Invalid Input. Try again.\n";
				break;
			}
		}
		catch (exception x)
		{
			cout << x.what() << endl;
			cin.clear();
			getline(cin, str);
		}
	}
}


int main()
{

	runlibrary();
	
	// Pause before application window closes
	cout << "Press any key to exit ..." << endl;
	_getch();

}
