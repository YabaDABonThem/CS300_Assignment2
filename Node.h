#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node *next = NULL;
		Node(char data) {
        	this->data = data;
    	}
		Node() {

		}
};

#endif
