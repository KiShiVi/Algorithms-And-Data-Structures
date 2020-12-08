#ifndef STACK_INL
#define STACK_INL
#include "stack.h"

// class nodeQueue

template <class T>
class stack<T>::nodeStack {
private:
	T _value;
	nodeStack* _next;
public:
	nodeStack() : _next(nullptr) {};
	nodeStack(T value, nodeStack* next) :
		_value(value), _next(next) {}
	T getValue() {
		return _value;
	}
	void setValue(T value) {
		_value = value;
	}
	nodeStack* getNext() {
		return _next;
	}
	void setNext(nodeStack* next) {
		_next = next;
	}
};


// methods queue

template <class T>
stack<T>::stack() : _head(nullptr), _size(0) {}

template<class T>
stack<T>::~stack()
{
	while (_size > 0)
		this->pop();
}



template <class T>
T stack<T>::pop() {
	if (_size == 0)
		throw "queue error";
	nodeStack* temp = _head;
	T tempVal = _head->getValue();
	_head = _head->getNext();
	delete temp;
	_size--;
	return tempVal;
}



template <class T>
void stack<T>::push(T value) {
	if (_size == 0) {
		_head = new nodeStack(value, nullptr);
		_size++;
		return;
	}
	_head = new nodeStack(value, _head);
	_size++;
	return;
}



template <class T>
int stack<T>::getSize() {
	return _size;
}


#endif	