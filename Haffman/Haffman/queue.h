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
	T front();
};

template <class T>
class queue<T>::nodeQueue {
private:
	T _value;
	nodeQueue* _next;
public:
	nodeQueue() : _next(nullptr) {};
	nodeQueue(T value, nodeQueue* next) :
		_value(value), _next(next) {}
	T getValue() {
		return _value;
	}
	void setValue(T value) {
		_value = value;
	}
	nodeQueue* getNext() {
		return _next;
	}
	void setNext(nodeQueue* next) {
		_next = next;
	}
};


// methods queue

template <class T>
queue<T>::queue() : _head(nullptr), _tail(nullptr), _size(0) {}




template<class T>
queue<T>::~queue()
{
	while (_size > 0)
		this->pop();
}



template <class T>
T queue<T>::pop() {
	if (_size == 0)
		throw "queue error";
	nodeQueue* temp = _head;
	T tempVal = _head->getValue();
	_head = _head->getNext();
	delete temp;
	_size--;
	if (_head == nullptr)
		_tail = _head;
	return tempVal;
}



template <class T>
void queue<T>::push(T value) {
	if (_size == 0) {
		_head = new nodeQueue(value, nullptr);
		_tail = _head;
		_size++;
		return;
	}
	_tail->setNext(new nodeQueue(value, nullptr));
	_tail = _tail->getNext();
	_size++;
	return;
}



template <class T>
int queue<T>::getSize() {
	return _size;
}

template <class T>
T queue<T>::front() {
	return this->_head->getValue();
}


#endif
