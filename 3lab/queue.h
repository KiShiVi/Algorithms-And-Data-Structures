#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class queue {
private:
	class nodeQueue;
	nodeQueue* _head;
	nodeQueue* _tail;
	int _size;
public:
	queue();
	~queue();
	T pop();
	void push(T value);
	int getSize();

};

#include "queue.inl"
#endif // !1