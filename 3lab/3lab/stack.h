#ifndef STACK_H
#define STACK_H

template<class T>
class stack {
private:
	class nodeStack;
	nodeStack* _head;
	int _size;
public:
	stack();
	~stack();
	T pop();
	void push(T value);
	int getSize();

};

#include "stack.inl"
#endif // !1