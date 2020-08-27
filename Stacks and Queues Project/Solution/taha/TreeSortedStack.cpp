#include <iostream>
#include <string>
#include "TreeSortedStack.h"
using namespace std;

TreeSortedStack::TreeSortedStack(int initialCapacity) {
	capacity = initialCapacity;
	elements = new int[capacity];
	size = 0;
}

TreeSortedStack::~TreeSortedStack() {
	delete[] elements;
}

int TreeSortedStack::getSize(){
	return size;
}

int TreeSortedStack::peek(){
	if (size == 0){
		cout << "Structure is empty. pop returning -1 as placeholder."<<endl;
		return -1;
	}
	else{
		return elements[1];
	}
}

bool TreeSortedStack::isEmpty(){
	if (size == 0){
		return true;
	}
	else{
		return false;
	}
}

void TreeSortedStack::push(int x){
	shiftRight();
	elements[size+1] = x;
	size++;
	int childID = size;	
	int parentID = (childID / 2);	
	while (elements[parentID] > elements[childID] && childID > 0){
			int y = elements[parentID];
			elements[parentID] = elements[childID];
			elements[childID] = y;
			childID = parentID;
			parentID = (childID / 2);
	}
}
	
int TreeSortedStack::pop(){
	if (size == 0){
		cout << "Structure is empty. pop returning -1 as placeholder." << endl;
		return -1;
	}
	else{
		int value = elements[1];
		elements[1] = elements[size];
		size--;
		int parentID = 1;
		int smallestID = 0;
		if (elements[parentID * 2] > elements[(parentID * 2) + 1]){
			smallestID = (parentID * 2) + 1;
		}
		else{
			smallestID = (parentID * 2);
		}	
		while ((smallestID <= size) && elements[parentID] > elements[smallestID]){ 
			int y = elements[parentID]; 
			elements[parentID] = elements[smallestID];
			elements[smallestID] = y;
			parentID = smallestID; 
			if (elements[parentID * 2] > elements[(parentID * 2) + 1] ){
				smallestID = (parentID * 2) + 1;
			}
			else if (elements[parentID * 2] < elements[(parentID * 2) + 1] ){
				smallestID = parentID * 2;
			}
		}
		return value;
	}
}
void TreeSortedStack::shiftRight(){
	if (size + 1 == capacity)
		expandArray();
}

void TreeSortedStack::expandArray() {
	int newCapacity = capacity * 2;
	int* bigger = new int[newCapacity];
	for (int i = 0; i <= size; i++)
		bigger[i] = elements[i];
	delete[] elements;
	elements = bigger;
	capacity = newCapacity;
}

void TreeSortedStack::printSpaces(int numSpaces) {
	for (int i = 0; i < numSpaces; i++)
		cout << " ";
}

void TreeSortedStack::printHelper(int i, int depth, char header) {
	if (i < size + 1) {
		printSpaces(depth * 4);
		if (i != 1)
			cout << header << ": ";

		cout << elements[i] << endl;
		printHelper(i * 2, depth + 1, 'L');
		printHelper((i * 2) + 1, depth + 1, 'R');
	}
}

void TreeSortedStack::print() {
	cout << "-------------------------------" << endl;
	printHelper(1, 0, ' ');
	cout << "-------------------------------" << endl;
}
