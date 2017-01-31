#include <iostream>
#include "node.h"
#include "stack.cpp"

using namespace std;

int main() {

	stack<int> s1;
	int value;
	char choice;

	do {
		cout << "p - push\nP - pop\ne - empty\nE - check if empty\nQ - Quit\n\n";
		cin >> choice;
		switch (choice) {
		case 'p':
			cout << "Enter value: ";
			cin >> value;
			s1.push(value);
			break;
		case 'P':
			cout << s1.pop() << endl;
			break;
		case 'e':
			s1.empty();
			break;
		case 'E':
			if (s1.isEmpty())
				cout << "Empty\n";
			else
				cout << "Items remaining\n";
			break;
		case 'Q':
			continue;
		default:
			cout << "Enter a valid input\n";
		}
	} while (choice != 'Q');

	return 0;
}