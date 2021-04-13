#ifndef HAFFMAN_H
#define HAFFMAN_H
#include <stdlib.h>
#include <string>
#include "list.h"
#include "queue.h"
#include "RBTree.h"

class HaffmanTree {
private:
	class nodeHaffman {
	public:
		nodeHaffman* _parent;
		nodeHaffman* _left;
		nodeHaffman* _right;
		std::string _code;

		char _value;

		nodeHaffman(nodeHaffman* parent, nodeHaffman* left, nodeHaffman* right, char value) :
			_parent(parent), _left(left), _right(right), _value(value), _code("") {};

		void setParent(nodeHaffman* parent) {
			_parent = parent;
		}

		void setCode(std::string code) {
			_code = code;
		}
	};

	int _power;
	nodeHaffman* _root;

public:
	nodeHaffman* getRoot() {
		return _root;
	}

	int getPower() {
		return _power;
	}

	HaffmanTree(char value, int power) :
		_power(power) {
		_root = new nodeHaffman(nullptr, nullptr, nullptr, value);
	}

	HaffmanTree(HaffmanTree* leftTree, HaffmanTree* rightTree){
		_power = leftTree->getPower() + rightTree->getPower();
		_root = new nodeHaffman(nullptr, leftTree->getRoot(), rightTree->getRoot(), NULL);
		_root->_left->setParent(_root);
		_root->_right->setParent(_root);
	}

	void RLK(nodeHaffman* node)
	{
		if (node != nullptr)
		{
			if (node->_right != nullptr) {
				node->_right->_code = node->_code + "1";
				RLK(node->_right);
			}
			if (node->_left != nullptr) {
				node->_left->_code = node->_code + "0";
				RLK(node->_left);
			}
		}
	}

	void toRbTree(RBTree<char, std::string>* tree, nodeHaffman* node)
	{
		if (node != nullptr)
		{
			if (node->_right != nullptr) {
				toRbTree(tree, node->_right);
			}
			if (node->_left != nullptr) {
				toRbTree(tree, node->_left);
			}
			if (node->_value != 0)
				tree->insert(node->_value, node->_code);

		}
	}

	std::string decode(std::string encodeInput) {
		std::string _out = "";
		nodeHaffman* node = _root;
		for (int i = 0; i < encodeInput.length(); i++) {
			if (encodeInput[i] == '0')
				node = node->_left;
			else if (encodeInput[i] == '1')
				node = node->_right;
			if (node->_value != 0) {
				_out += node->_value;
				node = _root;
			}
		}
		return _out;
	}
};



#endif