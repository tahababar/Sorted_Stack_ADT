#include <iostream>
using namespace std;
#include "TreeSortedStack.h"

void officialTest() {
	TreeSortedStack tss(2);

	cout << "isEmpty: " << tss.isEmpty() << endl;

	cout << "push 10" << endl;
	tss.push(10);
	tss.print();

	cout << "push 12" << endl;
	tss.push(12);
	tss.print();

	cout << "push 5" << endl;
	tss.push(5);
	tss.print();

	cout << "push 7" << endl;
	tss.push(7);
	tss.print();

	cout << "push 9" << endl;
	tss.push(9);
	tss.print();

	cout << "pop: " << tss.pop() << endl;
	cout << "peek: " << tss.peek() << endl;
	tss.print();

	cout << "push 16" << endl;
	tss.push(16);
	tss.print();

	cout << "push 13" << endl;
	tss.push(13);
	tss.print();

	cout << "push 4" << endl;
	tss.push(4);
	tss.print();

	cout << "push 11" << endl;
	tss.push(11);
	tss.print();

	cout << "==========================================" << endl;

	cout << "getSize: " << tss.getSize() << endl;
	cout << "peek: " << tss.peek() << endl;

	while (!tss.isEmpty()) {
		cout << "pop: " << tss.pop() << endl;
		//cout << "Result: " << tss.pop() << endl;
		tss.print();
	}

	cout << "==========================================" << endl;
	cout << "getSize: " << tss.getSize() << endl;
	cout << "peek: " << tss.pop() << endl;
	cout << "pop: " << tss.pop() << endl;
}

int main() {
	officialTest();

	return 0;
}
