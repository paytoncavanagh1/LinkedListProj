
#include <iostream>
#include "area_node.h"

using namespace std;

#define NUM_TO_PRINT_PER_LINE 5

AreaNode::AreaNode(int areaCode)
{
    this->areaCode = areaCode;
    AreaNumberPtr = NULL; // numberNode
    next = NULL; // areaNode
}

//-----------------------------------------------------------------------
// DO NOT MODIFY THIS PRINT FUNCTION
// BIG-O RUN TIME OF THIS FUNCTION: 

void AreaNode::print()
{
    NumberNode* temp = AreaNumberPtr;
    if (temp == NULL)
        cout << "There are no phone numbers in this area code\n";

    for (int x = 0; x < size() && temp != NULL; x += NUM_TO_PRINT_PER_LINE)
    {
        cout << "       " << flush;
        for (int y = 0; y < NUM_TO_PRINT_PER_LINE && temp != NULL; y++, temp = temp->numberPtr)
        {
            cout << temp->prefix << "-" << flush << temp->suffix << ", " << flush;
        }
        cout << endl;
    }
}

//-----------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 

int AreaNode::size()
{
    int count = 0;
    NumberNode* current = AreaNumberPtr;
    while (current != NULL)
    {
        count++;
        current = current->numberPtr;
    }
    return count;
}

//-----------------------------------------------------------------------

bool AreaNode::isEmpty()
{
    if (AreaNumberPtr == NULL)
        return true;
    else
        return false;
}

void AreaNode::removeNumber(int prefix, int suffix)
{
    NumberNode* current = AreaNumberPtr;
    NumberNode* previous = NULL;

    // iterating through linked list
    while (current != NULL && (current->prefix != prefix || current->suffix != suffix)) {
        previous = current;
        current = current->numberPtr;
    }

    // if prefix and suffix aren't found
    if (current == NULL)
    {
        cout << prefix << " and " << suffix << " were not in the list\n";
    }
    else
    {
        // Found the number to remove
        if (previous == NULL) {
            // The number is the head of the list
            AreaNumberPtr = current->numberPtr;
        }
        else {
            previous->numberPtr = current->numberPtr;
        }
        delete current;
        cout << "The number " << prefix << " " << suffix << " was deleted\n";
    }
}

void AreaNode::insertNumber(int prefix, int suffix, AreaNode* AreaHead)
{
    NumberNode* newPreSuf = new NumberNode(prefix, suffix);

    if (search(prefix, suffix) != NULL) {
        cout << "Error: cannot insert duplicate numbers\n";
        delete newPreSuf;
        return;
    }

    // checking if we have a list
    // head
    if (AreaNumberPtr != NULL)
    {
        // make the current pointer point to the front of the list
        newPreSuf->numberPtr = AreaNumberPtr;
        AreaNumberPtr = newPreSuf;
    }
    else
    {
        AreaNumberPtr = newPreSuf;
    }

    // connect area node (909) to number node once the list is complete
    AreaHead->AreaNumberPtr = newPreSuf;
}

NumberNode* AreaNode::search(int prefix, int suffix)
{
    NumberNode* current = AreaNumberPtr;

    while (current != NULL)
    {
        if (current->prefix == prefix && current->suffix == suffix)
        {
            return current;
        }
        current = current->numberPtr;
    }

    return NULL; // number not found
}

int AreaNode::numPrefixNumbers(int prefix)
{
    int count = 0;
    NumberNode* current = AreaNumberPtr;

    while (current != NULL) {
        if (current->prefix == prefix) {
            count++;
        }
        current = current->numberPtr;
    }

    return count;
}

int AreaNode::getArea()
{
    return areaCode;
}