#include <iostream>
#include <list>
#include "RBTree.h"

using namespace std;

int main() {
	RBTree<int, int> tree;
	tree.insert(1, 5);
	tree.insert(2, 4);
	tree.insert(3, 3);
	tree.insert(4, 2);
	tree.insert(5, 1);
	tree.remove(2);
	cout << "\n";
	list<int> a = tree.get_keys();
	for (list<int>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it << " ";

	cout << "\n";
	a = tree.get_values();
	for (list<int>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it << " ";
	
	tree.print();
}