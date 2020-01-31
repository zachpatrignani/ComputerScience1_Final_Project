#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "library.h"
#include <string>
#include <vector>
using namespace std;

class magazine : public library
{
public:

	void setData(string i, string n, string is, string s);
	void loadMagazines();
	void magazinesMenu();
	void addMagazine();
	void setIssue(string v);
	string getIssue();
	magazine();
	magazine(string i, string n, string is, string s);


private:

	string issue;
	

};
#endif
