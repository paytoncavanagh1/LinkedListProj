#ifndef __PHONE_BOOK_H
#define __PHONE_BOOK_H

#include "area_node.h"

using namespace std;

class PhoneBook
{
private:
	AreaNode* head;

public:
	PhoneBook();
	void insertPhoneNumber(int, int, int);
	void removePhoneNumber(int, int, int);
	bool search(int, int, int);
	void print();
	int numNumbers();
	int numAreaCodeNumbers(int);
	int numAreaCodeAndPrefixNumbers(int, int);
	AreaNode* getHead();

};

#endif
