#include <iostream>
using namespace std;

class TreeSortedStack {
private:
	int size;
	int capacity;
	int* elements;
	void expandArray();
	void shiftRight();
	void printSpaces(int numSpaces);
	void printHelper(int i, int depth, char header);
	


public:
	TreeSortedStack(int initialCapacity);
	~TreeSortedStack();
	void print();
	void push(int x);
	int pop();
	int peek();
	int getSize();
	bool isEmpty();
};