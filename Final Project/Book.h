#ifndef BOOK_H
#define BOOK_H

#include "library.h"
#include <string>
#include <vector>
using namespace std;

class book : public library
{
public:
	
	void setData(string i, string n, string a, string s);
	void loadBooks();
	void booksMenu();
	void addBook();
	void setAuthor(string a);
	string getAuthor();
	book();
	book(string i, string n, string a, string s);


private:
	
	string authorName;
	
	
};
#endif
