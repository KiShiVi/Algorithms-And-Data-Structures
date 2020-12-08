#ifndef BST_H
#define BST_H

using namespace std;

template <class T>
class BinaryTree {
private:
	class BinaryNode {
	private:	
		T _value;
		BinaryNode* _left;
		BinaryNode* _right;
		BinaryNode* _parent;
	public:
		BinaryNode(T value, BinaryNode* parent);
		T getValue();
		void setValue(T value);
		BinaryNode* getLeft();
		void setLeft(BinaryNode* left);
		BinaryNode* getRight();
		void setRight(BinaryNode* right);
		BinaryNode* getParent();
		void setParent(BinaryNode* parent);
	};
	BinaryNode* _root;
	BinaryNode* search(T value);
public:

	class bft_iterator;
	class dft_iterator;
	BinaryTree();
	~BinaryTree();
	void insert(T value);
	bool contains(T value);
	void remove(T value);
	BinaryNode* begin();
};

#include "BST.inl"

#endif // ! BST_H
