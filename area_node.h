#ifndef __AREA_NODE_H
#define __AREA_NODE_H

#include "number_node.h"
#include "phone_book.h"

class AreaNode
{
	friend class PhoneBook;
private:
	int areaCode;
	AreaNode* next;
	NumberNode* AreaNumberPtr;

public:
	void print();
	int size();
	AreaNode(int areaCode);
	bool isEmpty();
	void removeNumber(int prefix, int suffix);
	void insertNumber(int prefix, int suffix, AreaNode* AreaHead);
	NumberNode* search(int prefix, int suffix);
	int numPrefixNumbers(int prefix);
	int getArea();


};

#endif
