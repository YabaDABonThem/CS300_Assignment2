#ifndef SLLSTRING_H
#define SLLSTRING_H

#include <iostream>
#include "Node.h"

using namespace std;

class SLLString {
    private:
        Node *head = nullptr; // store the head of the LinkedList

    public:
        SLLString() = default; // default constructor

        SLLString(const string& other); // constructor that takes a string
        SLLString(const SLLString& other); // copy constructor
        ~SLLString(); // destructor
        
        SLLString& operator=(const SLLString& other); // assignment constructor
        SLLString& operator+= (const SLLString& other); // concatenation
        
        int length() const; // get length of this string
        char& operator[](const int n); // get character at index n
        int findSubstring(const SLLString& substring); // find the index of the first occurrence of
        // substring in the current string. Returns -1 if not found
        void erase(char c); //erase all occurrences of character c from the current string
        friend ostream& operator<<(ostream&, const SLLString&); // support cout

        // other methods
        bool isEmpty() const;
        void destroy();
};

#endif