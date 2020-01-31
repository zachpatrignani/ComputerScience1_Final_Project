#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;


class library
{
public: 
	library();
	string addItem();
	string searchLibrary();
	void checkout(library& obj);
	void returnItem(library& obj);
	void setID(string i);
	void setName(string n);
	void setStatus(string s);
	string getID();
	string getName();
	string getStatus();

private:
	string id;
	string name;
	string status;
	
	
};

#endif