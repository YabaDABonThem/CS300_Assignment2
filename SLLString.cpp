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
    void destroy(); // when we destroy we need to keep track of the previous head
    // and delete it
}

SLLString& SLLString::operator=(const SLLString& other) {
    // update the values of this to the values of other
    // check if it's not already the same thing
    if (this != &other) { // check if the pointers point to the same thing
        // If we already have some items, get rid of them via the destructor
        if (!isEmpty()) destroy();

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
    // combine the two, move the pointer to the enter of this
    // and set the next to the beginning of other. 
    Node *thisPtr = head;
    Node *otherPtr = other.head;
    // Move thisPtr to the end of our SLLString
    while (thisPtr) thisPtr = thisPtr->next;

    // We now deep copy the values from other to this
    // this decreases the runtime to O(m+n), which is way faster then having a private method to add.
    while(otherPtr) {
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

int SLLString::findSubstring(const SLLString& substring) {
    // return the index of the first occurence of the substring
    // this is a common sliding window problem
    int numMatchingChars = 0; // keep track of the current matching char count
    Node *ptr = head;
    Node *substringPtr = substring.head;
    while (ptr) { // loop through the SLL
        if (numMatchingChars == substring.length())
    }
    return -1; // if we didn't frind the substring
}

int SLLString::length() const {
    // loop through all the nodes until you get the length
    if (isEmpty()) { // if it's Empty return 0
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
    if (s.isEmpty()) {
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

bool SLLString::isEmpty() const{
    return !head;
}

void SLLString::destroy(){
    Node *n = head;
    while(n){
        n = n->next;
        delete n;
        head = n;
    }
}

