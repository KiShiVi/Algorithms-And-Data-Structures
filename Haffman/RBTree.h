#include <iostream>
#include <string>
#include "queue.h"
#include "list.h"

using namespace std;

template <class T_key, class T_value>
class RBTree {
	class Node;

protected:
	Node* _nil;
	Node* _root;

private:
	enum class Color {
		Black,
		Red
	};
	class Node {
	public:
		Color _color;
		T_key _key;
		Node* _left;
		Node* _right;
		Node* _parent;
		T_value _value;

		Node() : _color(Color::Black), _key(0),
			_left(nullptr), _right(nullptr),
			_parent(nullptr) {}


		Node(Node* node) : _color(node->_color), _key(node->_key),
			_left(node->_left), _right(node->_right),
			_parent(node->_parent), _value(node->_value) {}


		Node(Color color, T_key key, Node* left, Node* right, Node* parent, T_value value) :
			_color(color), _key(key),
			_left(left), _right(right),
			_parent(parent), _value(value) {}

	};



	void leftRotate(Node* x) {
		Node* y = x->_right;
		x->_right = y->_left;

		if (y->_left != _nil)
			y->_left->_parent = x;

		if (y != _nil)
			y->_parent = x->_parent;

		if (x->_parent == _nil)
			_root = y;
		else if (x == x->_parent->_left)
			x->_parent->_left = y;
		else
			x->_parent->_right = y;

		y->_left = x;
		if (x != _nil)
			x->_parent = y;
	}



	void rightRotate(Node* y) {
		Node* x = y->_left;
		y->_left = x->_right;

		if (x->_right != _nil)
			x->_right->_parent = y;

		if (x != _nil)
			x->_parent = y->_parent;

		if (y->_parent == _nil)
			_root = x;
		else if (y == y->_parent->_right)
			y->_parent->_right = x;
		else
			y->_parent->_left = x;

		x->_right = y;
		if (y != _nil)
			y->_parent = x;
	}



	void rbInsertFixup(Node* z) {
		while (z != _root && z->_parent->_color == Color::Red) {
			if (z->_parent == z->_parent->_parent->_left) {
				Node* y = z->_parent->_parent->_right;
				if (y->_color == Color::Red) {
					z->_parent->_color = Color::Black;
					y->_color = Color::Black;
					z->_parent->_parent->_color = Color::Red;
					z = z->_parent->_parent;
				}
				else {
					if (z == z->_parent->_right) {
						z = z->_parent;
						leftRotate(z);
					}
					z->_parent->_color = Color::Black;
					z->_parent->_parent->_color = Color::Red;
					rightRotate(z->_parent->_parent);
				}
			}
			else {
				Node* y = z->_parent->_parent->_left;
				if (y->_color == Color::Red) {
					z->_parent->_color = Color::Black;
					y->_color = Color::Black;
					z->_parent->_parent->_color = Color::Red;
					z = z->_parent->_parent;
				}
				else {
					if (z == z->_parent->_left) {
						z = z->_parent;
						rightRotate(z);
					}
					z->_parent->_color = Color::Black;
					z->_parent->_parent->_color = Color::Red;
					leftRotate(z->_parent->_parent);
				}
			}
		}
		_root->_color = Color::Black;
	}



	void rbInsert(Node* z) {
		Node* y = _nil;
		Node* x = _root;

		while (x != _nil) {
			y = x;
			if (z->_key < x->_key)
				x = x->_left;
			else
				x = x->_right;
		}

		z->_parent = y;

		if (y == _nil)
			_root = z;
		else if (z->_key < y->_key)
			y->_left = z;
		else
			y->_right = z;

		z->_left = _nil;
		z->_right = _nil;
		z->_color = Color::Red;
		rbInsertFixup(z);
	}



	void deleteFixup(Node* x) {
		while (x != _root && x->_color == Color::Black) {
			if (x == x->_parent->_left) {
				Node* w = x->_parent->_right;
				if (w->_color == Color::Red) {
					w->_color = Color::Black;
					x->_parent->_color = Color::Red;
					leftRotate(x->_parent);
					w = x->_parent->_right;
				}
				if (w->_left->_color == Color::Black && w->_right->_color == Color::Black) {
					w->_color = Color::Red;
					x = x->_parent;
				}
				else {
					if (w->_right->_color == Color::Black) {
						w->_left->_color = Color::Black;
						w->_color = Color::Red;
						rightRotate(w);
						w = x->_parent->_right;
					}
					w->_color = x->_parent->_color;
					x->_parent->_color = Color::Black;
					w->_right->_color = Color::Black;
					leftRotate(x->_parent);
					x = _root;
				}
			}
			else {
				Node* w = x->_parent->_left;
				if (w->_color == Color::Red) {
					w->_color = Color::Black;
					x->_parent->_color = Color::Red;
					rightRotate(x->_parent);
					w = x->_parent->_left;
				}
				if (w->_right->_color == Color::Black && w->_left->_color == Color::Black) {
					w->_color = Color::Red;
					x = x->_parent;
				}
				else {
					if (w->_left->_color == Color::Black) {
						w->_right->_color = Color::Black;
						w->_color = Color::Red;
						leftRotate(w);
						w = x->_parent->_left;
					}
					w->_color = x->_parent->_color;
					x->_parent->_color = Color::Black;
					w->_left->_color = Color::Black;
					rightRotate(x->_parent);
					x = _root;
				}
			}
		}
		x->_color = Color::Black;
	}



	void deleteNode(Node* z) {
		Node* x, * y;

		if (z == _nil)
			return;

		if (z->_left == _nil || z->_right == _nil)
			y = z;
		else {
			y = z->_right;
			while (y->_left != _nil) y = y->_left;
		}

		if (y->_left != _nil)
			x = y->_left;
		else
			x = y->_right;

		x->_parent = y->_parent;
		if (y->_parent != _nil) {
			if (y == y->_parent->_left)
				y->_parent->_left = x;
			else
				y->_parent->_right = x;
		}
		else
			_root = x;

		if (y != z) {
			z->_key = y->_key;
			z->_value = y->_value;
		}

		if (y->_color == Color::Black)
			deleteFixup(x);

		delete y;
	}



	Node* findNode(T_key key) {
		Node* it = _root;
		while (it->_key != key && it != _nil) {
			if (it->_key < key)
				it = it->_right;
			else
				it = it->_left;
		}
		if (it == _nil)
			return(nullptr);
		return it;
	}



	void recursionForClear(Node* x) {
		if (x->_left != _nil)
			recursionForClear(x->_left);
		if (x->_right != _nil)
			recursionForClear(x->_right);
		delete x;

	}

public:

	class iterator : public RBTree {
	private:
		queue<Node*> _queueIt;
		T_value _value;
		T_key _key;
		Node* _it;
		Node* _nil;
	public:

		iterator(RBTree* tree) : _it(NULL),
			_value(tree->_root->_value), _key(tree->_root->_key), _nil(tree->_nil) {
			_queueIt.push(tree->_root);
		}

		const T_value& operator++() {
			if (_queueIt.getSize() == 0)
				return NULL;
			_it = _queueIt.front();
			_queueIt.pop();
			if (_it->_left != _nil)
				_queueIt.push(_it->_left);
			if (_it->_right != _nil)
				_queueIt.push(_it->_right);
			_value = _it->_value;
			_key = _it->_key;
			return _it->_value;
		}

		const T_key& operator*() {
			return _key;
		}


		const T_value& getValue() {
			return _value;
		}
	};



	RBTree() {
		_nil = new Node();
		//_nil->_parent = _nil;
		//_nil->_left = _nil;
		//_nil->_right = _nil;
		_root = _nil;
	}



	void insert(T_key key, T_value value) {
		Node* node = new Node(Color::Red, key, nullptr, nullptr, nullptr, value);
		rbInsert(node);
	}



	T_value find(T_key key) {
		if (findNode(key))
			return findNode(key)->_value;
		return 0;
	}



	void remove(T_key key) {
		deleteNode(findNode(key));
	}



	void clear() {
		recursionForClear(_root);
		_root = _nil;
	}



	list<T_key> get_keys() {
		list<T_key> _out;
		iterator it(this);
		while (++it != NULL) {
			_out.push(*it);
		}
		return _out;
	}



	list<T_value> get_values() {
		list<T_value> _out;
		iterator it(this);
		while (++it != NULL) {
			_out.push(it.getValue());
		}
		return _out;
	}



	void print() {
		iterator it(this);
		cout << '\n';
		while (++it != NULL) {
			cout << *it << " ";
		}
	}

	int getSize() {
		int i = 0;
		iterator it(this);
		while (++it != NULL) {
			i++;
		}
		return i;
	}
};

#pragma once