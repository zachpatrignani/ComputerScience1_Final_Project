#ifndef JOURNAL_H
#define JOURNAL_H

#include "library.h"
#include <string>
#include <vector>
using namespace std;

class journal : public library
{
public:

	void setData(string i, string n, string v, string s);
	void loadJournals();
	void journalsMenu();
	void addJournal();
	void setVolume(string v);
	string getVolume();
	journal();
	journal(string i, string n, string v, string s);


private:

	string volume;
	

};
#endif
