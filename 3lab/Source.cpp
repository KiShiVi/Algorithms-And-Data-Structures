#include <iostream>
#include "BST.h"
#include "queue.h"

using namespace std;

int main() {

	BinaryTree<int>* binarytree = new BinaryTree<int>;
	binarytree->insert(8);
	binarytree->insert(3);
	binarytree->insert(1);
	binarytree->insert(6);
	binarytree->insert(4);
	binarytree->insert(7);
	binarytree->insert(10);
	binarytree->insert(14);
	binarytree->insert(13);
	binarytree->remove(3);

	BinaryTree<int>::dft_iterator it(binarytree->begin());
	for (int i = 0; i < 9; i++) {
		cout << *it << " ";
		++it;
	}
	delete binarytree;

	return 0;
}