#ifndef __NUMBER_NODE_H
#define __NUMBER_NODE_H
#include <iostream>

class NumberNode
{
	friend class AreaNode;
private:
	int prefix;
	int suffix;
	NumberNode* numberPtr;
	NumberNode* value;

public:
	NumberNode(int prefix, int suffix);
	int getPrefix() const;
	int getSuffix() const;
	NumberNode* getNext() const;
};

#endif
