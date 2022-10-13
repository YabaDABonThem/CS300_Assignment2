#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		char data;
		Node *next = NULL;
		Node(char data) : data(data) {}
		Node() {
			
		}
};

#endif
