#include "SLLString.h"
#include <iostream>

// using namespace std;

SLLString::SLLString(const string& other) {

}

SLLString::SLLString(const SLLString& other) {
    // can't access the SLL, so get char at every index
    // and create a new SLL with those chars.
    // there is no add so how do you create it
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

// SLLString& SLLString::operator+= (const SLLString& other) {

// }

// char& SLLString::operator[](const int n) {
//     if (n > length()-1) {
//         std::cout << "Index out of bound" << std::endl;
//         // EXIT
//     }
// }

// int length() {
//     // loop through all the nodes until you get the length
//     if (head == NULL) { // if it's Empty return 0
//         return 0;
//     }

//     int stringLength = 0;
//     Node *n = head;
//     while (n != NULL) {
//         ++stringLength;
//         n = n.next;
//     }
//     return stringLength;
// }

void SLLString::print() const{
    if (isEmpty()) {
        std::cout << endl;
        return;
    }
    Node *n = head;
    while(n->next) {
        std::cout << n->data << "->";
    }
    std::cout << n->data << endl; // fenceposting

}

bool SLLString::isEmpty() const{
    return head == NULL;
}

void SLLString::destroy(){
    Node *n = head;
    while(n){
        n = n->next;
        delete n;
        head = n;
    }
}

