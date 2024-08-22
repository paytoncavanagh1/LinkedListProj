#include "number_node.h"

NumberNode::NumberNode(int prefix, int suffix)
{
	this->prefix = prefix;
	this->suffix = suffix;
    // NumHead = NULL;
}

int NumberNode::getPrefix() const 
{
    return prefix;
}

int NumberNode::getSuffix() const 
{
    return suffix;
}

NumberNode* NumberNode::getNext() const 
{
    return numberPtr;
}