#ifndef BST_INL
#define BST_INL


#include "BST.h"
#include "queue.h"
#include "stack.h"
#include <iostream>



// iterator classes

template <class T>
class BinaryTree<T>::bft_iterator {
private:
	BinaryNode* _it;
	queue<BinaryNode*>* _queueIt = new queue<BinaryNode*>;
public:
	bft_iterator(BinaryNode* root) : _it(root) {
		_queueIt->push(root);
	}
	bft_iterator() : _it(nullptr) {}

	const T& operator++() {
		if (_queueIt->getSize() == 0)
			return NULL;
		_it = _queueIt->pop();
		if (_it->getLeft() != nullptr)
			_queueIt->push(_it->getLeft());
		if (_it->getRight() != nullptr)
			_queueIt->push(_it->getRight());
		return _it->getValue();	
	}
	const T& operator*() {
		return _it->getValue();
	}
	BinaryNode* getAdd() { return _it; };
};



template <class T>
class BinaryTree<T>::dft_iterator {
private:
	BinaryNode* _it;
	stack<BinaryNode*>* _stackIt = new stack<BinaryNode*>;
public:
	dft_iterator(BinaryNode* root) : _it(root) {
		_stackIt->push(root);
	}
	dft_iterator() : _it(nullptr) {}

	const T& operator++() {
		if (_it->getLeft() == nullptr && _stackIt->getSize() == 0)
			return NULL;
		if (_it->getRight() != nullptr)
			_stackIt->push(_it->getRight());
		if (_it->getLeft() != nullptr) {
			_it = _it->getLeft();
		}
		else {
			_it = _stackIt->pop();
		}
		return _it->getValue();
	}
	const T& operator*() {
		return _it->getValue();
	}
};



//BinaryNode Methods

template <class T>
BinaryTree<T>::BinaryNode::BinaryNode(T value, typename BinaryTree<T>::BinaryNode* parent) {
	_value = value;
	_left = nullptr;
	_right = nullptr;
	_parent = parent;
}



template <class T>
T BinaryTree<T>::BinaryNode::getValue() {
	return _value;
}



template <class T>
void BinaryTree<T>::BinaryNode::setValue(T value) {
	_value = value;
}



template <class T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::BinaryNode::getLeft() {
	return _left;
}



template <class T>
void BinaryTree<T>::BinaryNode::setLeft(BinaryNode* left) {
	_left = left;
}



template <class T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::BinaryNode::getRight() {
	return _right;
}



template <class T>
void BinaryTree<T>::BinaryNode::setRight(BinaryNode* right) {
	_right = right;
}



template <class T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::BinaryNode::getParent() {
	return _parent;
}



template <class T>
void BinaryTree<T>::BinaryNode::setParent(BinaryNode* parent) {
	_parent = parent;
}



template <class T>
 BinaryTree<T>::BinaryTree() {
	_root = nullptr;
}




template<class T>
BinaryTree<T>::~BinaryTree()
{
	BinaryTree<int>::bft_iterator it(_root);
	while (true){
		if (++it == NULL)
			return;
		delete it.getAdd();
	}
}



template <class T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::search(T value) {
	BinaryNode* node = _root;
	while (node != nullptr) {
		if (value < node->getValue())
			node = node->getLeft();
		else if (value > node->getValue())
			node = node->getRight();
		else
			return node;
	}
	return NULL;
}



template <class T>
void BinaryTree<T>::insert(T value) {
	if (_root == nullptr)
		_root = new BinaryNode(value, NULL);
	else {
		//BinaryNode* prevNode = NULL;
		BinaryNode* node = _root;

		while (true) {
			if (value <= node->getValue()) {
				if (node->getLeft() != nullptr) {
					//prevNode = node;
					node = node->getLeft();
				}
				else {
					node->setLeft(new BinaryNode(value, node));
					break;
				}
			}
			else {
				if (node->getRight() != nullptr) {
					//prevNode = node;
					node = node->getRight();
				}
				else {
					node->setRight(new BinaryNode(value, node));
					break;
				}
			}
		}
	}
}



template <class T>
bool BinaryTree<T>::contains(T value) {
	BinaryNode* node = _root;
	while (node != nullptr){
		if (value < node->getValue())
			node = node->getLeft();
		else if (value > node->getValue())
			node = node->getRight();
		else
			return true;
	}
	return false;
}



template <class T>
void BinaryTree<T>::remove(T value){
	BinaryNode* node = search(value);
	if (node == NULL)
		return;
	if (node->getLeft() == nullptr && node->getRight() == nullptr) {	// hasn't children
		if (node->getParent()->getLeft() == node) {	// node is on the left about parent
			node->getParent()->setLeft(nullptr);
			delete node;
		}
		else {											// node is on the right about parent
			node->getParent()->setRight(nullptr);
			delete node;
		}
	}
	else if(node->getLeft() == nullptr && node->getRight() != nullptr) { //Child on the right
		if (node->getParent()->getLeft() == node) {	// cnode is on the left about parent
			node->getParent()->setLeft(node->getRight());
			node->getRight()->setParent(node->getParent());
			delete node;
		}
		else {											// node is on the right about parent
			node->getParent()->setRight(node->getRight());
			node->getRight()->setParent(node->getParent());
			delete node;
		}
	}
	else if (node->getLeft() != nullptr && node->getRight() == nullptr) { //Child on the left
		if (node->getParent()->getLeft() == node) {	// node is on the left about parent
			node->getParent()->setLeft(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			delete node;
		}
		else {											// node is on the right about parent
			node->getParent()->setRight(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			delete node;
		}
	}
	else { // Two children
		BinaryNode* temp = node->getRight();
		while (temp->getLeft() != nullptr)
			temp = temp->getLeft();
		node->setValue(temp->getValue());


		if (temp->getRight() == nullptr) {
			if (temp->getParent()->getLeft() == temp) {	// node is on the left about parent
				temp->getParent()->setLeft(nullptr);
				delete temp;
			}
			else {											// child is on the right
				temp->getParent()->setRight(nullptr);
				delete temp;
			}
		}
		else {
			if (temp->getParent()->getLeft() == temp) {	// node is on the left about parent
				temp->getParent()->setLeft(temp->getRight());
				temp->getRight()->setParent(temp->getParent());
				delete temp;
			}
			else {											// child is on the right
				temp->getParent()->setRight(temp->getRight());
				temp->getRight()->setParent(temp->getParent());
				delete temp;
			}
		}
	}
}



template <class T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::begin() {
	return _root;
}
#endif