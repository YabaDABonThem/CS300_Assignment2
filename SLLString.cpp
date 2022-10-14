#include "SLLString.h"
#include <iostream>

// using namespace std; // debug purposes

SLLString::SLLString(const string& other) {
    // fenceposting is dum asf
    head = new Node(other[0]); // prevents head from being null;
    Node *ptr = head;

    for(int i = 1; i < other.size(); ++i, ptr = ptr->next) {
        ptr->next = new Node(other[i]);
    }
}

SLLString::SLLString(const SLLString& other) {
    // shallow copy
    head = other.head;
}

SLLString::~SLLString() {
    destroy(); // when we destroy we need to keep track of the previous head
    // and delete it
}

SLLString& SLLString::operator=(const SLLString& other) {
    // update the values of this to the values of other
    // check if it's not already the same thing
    if (this != &other) { // check if the pointers point to the same thing
        // If we already have some items, get rid of them via the destructor
        destroy();

        // set the first item equal to the head of the other.
        if (!other.head) {
            return *this; // we already destroyed this
        }
        const Node *otherNode = other.head;
        head = new Node(otherNode->data);
        Node *thisPtr = head;

        while (otherNode->next) { // loop through all the nodes in other
            otherNode = otherNode->next;
            thisPtr->next = new Node(otherNode->data); // set our nodes equal to the value of other's nodes
            thisPtr = thisPtr->next;
        }

    }
    return *this;
}

SLLString& SLLString::operator+= (const SLLString& other) {
    if (!head) {
        *this = other;
        return *this;
    }
    // combine the two, move the pointer to the enter of this
    // and set the next to the beginning of other. 
    Node *thisPtr = head;
    Node *otherPtr = other.head;
    // Move thisPtr to the last node of our SLLString
    while (thisPtr->next) thisPtr = thisPtr->next;

    // We now deep copy the values from other to this
    // this decreases the runtime to O(m+n), which is way faster then having a private method to add.
    while(otherPtr) {
        // _ASSERT(!thisPtr->next);
        thisPtr->next = new Node(otherPtr->data);
        otherPtr = otherPtr->next;
        thisPtr = thisPtr->next;
    }
    
    return *this;
}

char& SLLString::operator[](const int n) {

    if (n < 0 || n >= length()) { // If given invalid argument
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    Node *ptr = head;
    
    for (int i = 0; i < n; ++i) {
        ptr = ptr->next; // loop through the SLL n amount of times
    }
    
    return ptr->data; // return the data at index n-1
}

int SLLString::findSubstring(const SLLString& substring) const {
    // return the index of the first occurence of the substring
    // this is a common sliding window problem
    int startMatch = 0; // index where they began matching
    Node *ptr = head;
    
    while (ptr) { // loop through the SLL (we need to track the)
        if (isPrefix(ptr, substring)) {
            return startMatch; // if they match, return the index where they match
        }
        ++startMatch;
        ptr = ptr->next;
    }
    return -1; // if we didn't find the substring
}

bool SLLString::isPrefix(const Node *stringPtr, const SLLString& substring) const {
    // helper method to see if substring is the prefix of our SSLString
    Node *substringPtr = substring.head;

    while (substringPtr) { // go through to length of the substring to make sure every char matches
        // edge case where the substring is longer than the string itself
        if (!stringPtr || stringPtr->data != substringPtr->data) {
            return false;
        }
        stringPtr = stringPtr->next;
        substringPtr = substringPtr->next;
    }
    return true;
}

void SLLString::erase(char c) {
    if (!head) return; // edge case: head is null
    // iterate through the SSL and remove all instances of the character
    // You need to be able to "patch up" the holes in the SLL
    Node *currPtr = head;
    Node *prevPtr = NULL; // set this before head moves
    // NOTE: do we need to keep track of the Node we're deleting?
    while(currPtr) {
        if (currPtr->data != c) { // normal case (character doesn't get deleted))
            prevPtr = currPtr;
            currPtr = currPtr->next;
            continue;
        }
        // case: character needs to get deleted
        // edge case: the first item needs to be deleted
        if (currPtr == head) {
            // prev pointer is still null
            head = head->next; // there is a new head
            delete currPtr;
            currPtr = head;
        } else { // prev pointer is no longer null due to the first if statement
            prevPtr->next = currPtr->next; // set next to prev to next of curr
            delete currPtr; // delete the Node and make it point to the one after prevPtr
            currPtr = prevPtr->next; 
        }
        


    }
}

int SLLString::length() const {
    // loop through all the nodes until you get the length
    if (!head) { // if it's Empty return 0
        return 0;
    }

    int stringLength = 0;
    Node *n = head;
    
    while (n) { // loops through all items to find the length
        ++stringLength;
        n = n->next;
    }

    return stringLength;
}

ostream& operator<<(ostream& os, const SLLString& s) {
    // std::cout << "printed" << endl;
    if (!s.head) {
        return os;
    }
    Node *n = s.head;
    while(n) {
        os << n->data << "->";
        n = n->next;
    }
    os << "NULL" << endl; // last one always points to NULL
    return os;
}

void SLLString::destroy(){
    while(head){
        Node *n = head;
        head = head->next;
        delete n;
    }
}

