
#include <iostream>
#include <string>
#include "phone_book.h"

using namespace std;

PhoneBook::PhoneBook()
{
    head = NULL;
}

//-------------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 

void PhoneBook::removePhoneNumber(int area, int prefix, int suffix)
{
    AreaNode* current = head;

    // check if phone book is empty
    if (head == NULL)
        return;

    if (head->areaCode == area) {
        head->removeNumber(prefix, suffix);

        if (head->AreaNumberPtr == NULL) {
            AreaNode* temp = NULL;
            temp = head;
            head = temp->next;
            
            delete temp;
        }
    }
    else if (head->areaCode != area) {
        while (current != NULL) {
            if (current->next != NULL && current->next->areaCode == area)
                break; // current points to node above
            current = current->next;
        }
        // found our value
        if (current != NULL) {
            AreaNode* killMe = current->next; // this is the area code we want
            killMe->removeNumber(prefix, suffix);

            if (killMe->AreaNumberPtr == NULL) {
                AreaNode* temp = current->next;
                current->next = killMe->next;

                delete killMe;
            }
        }
    }
    else {
        cout << "Error: Phone number does not exist\n";
    }
}

AreaNode* PhoneBook::getHead() {
    return head;
}

//-------------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 
void PhoneBook::insertPhoneNumber(int area, int prefix, int suffix)
{
    AreaNode* currentArea = head;

    // check if phone book is empty
    if (head == NULL)
    {
        // if phone book is empty, create new area node and insert phone number
        head = new AreaNode(area);
        head->insertNumber(prefix, suffix, head);
    }

    while (currentArea != NULL) {
        if (currentArea->getArea() == area) { // find area code in phone book
            // if area code is found insert number into it
            currentArea->insertNumber(prefix, suffix, head);
            break;
        }
        else {
            currentArea = currentArea->next;
        }
    }

    if(search(area, prefix, suffix) == false) // if area code not found
    {
        AreaNode* newAreaNode = new AreaNode(area);
        newAreaNode->next = head;
        head = newAreaNode;
        newAreaNode->insertNumber(prefix, suffix, head);
    }
}

//-------------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 
bool PhoneBook::search(int area, int prefix, int suffix)
{
    AreaNode* areaNode = head;

    while (areaNode != NULL)
    {
        if (areaNode->areaCode == area) {
            // return true;
            if (areaNode->search(prefix, suffix) == NULL) {
                return false;
            }
            else
                return true;
        }
        else {
            areaNode = areaNode->next;
        }
    }
}

//-------------------------------------------------------------------------
// DO NOT MODIFY THIS PRINT FUNCTION
// BIG-O RUN TIME OF THIS FUNCTION: 
void PhoneBook::print()
{

    if (head == NULL)
    {
        cout << "Phonebook is empty" << endl;
    }
    else
    {
        for (AreaNode* temp = head; temp != NULL; temp = temp->next)
        {
            cout << "( " << temp->areaCode << " )" << endl;
            temp->print();
        }
    }

}

//-------------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 
int PhoneBook::numNumbers()
{
    int count = 0;
    AreaNode* current = head;
    while (current != NULL)
    {
        count += current->size();

        current = current->next;

    }
    return count;

    // return 0;
}

//-------------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 
int PhoneBook::numAreaCodeNumbers(int area)
{
    int count = 0;
    AreaNode* current = head;
    if (head == NULL) {
        return 0;
    }
    else if (head->areaCode == area) {
        while (current != NULL)
        {
            // get amount of numbers in a specific area code
            count += current->size();

            current = current->next;

        }
        return count;
    }
}

//-------------------------------------------------------------------------
// BIG-O RUN TIME OF THIS FUNCTION: 
int PhoneBook::numAreaCodeAndPrefixNumbers(int area, int prefix)
{
    int count = 0;
    AreaNode* currentArea = head;

    // Find the AreaNode with the matching area code
    while (currentArea != nullptr && currentArea->getArea() != area) {
        currentArea = currentArea->next;
    }

    if (currentArea != nullptr) {
        // Area code found, count the numbers with the matching prefix
        count = currentArea->numPrefixNumbers(prefix);
    }
    else {
        // Area code not found, no numbers to count
        // You could potentially print an error message here if desired
    }

    return count;
}
