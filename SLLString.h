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
        char& operator[](const int n) const; // get character at index n
        int findSubstring(const SLLString& substring) const; // find the index of the first occurrence of
        int findSubstring(const std::string& substring) const;
        // substring in the current string. Returns -1 if not found
        void erase(char c); //erase all occurrences of character c from the current string
        friend ostream& operator<<(ostream&, const SLLString&); // support cout

    private:
        // other helper methods
        bool isPrefix(const Node *stringPtr, const SLLString& substring) const;
        void destroy();

    friend class SLLStringTest;
};

#endif