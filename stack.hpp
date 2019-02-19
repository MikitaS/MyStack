#pragma once
#include <iostream>
#include "memory.hpp"

static const size_t START_STACK_SIZE_ = 50;

template <typename type>
class Stack
{
public:
///Constructors and destructor:
	Stack();
	Stack(Stack const & other); 
	~Stack();

///Methods:
	bool is_empty() const;
	void push(type data);
	type pop();
	size_t size();

///Operators:
	Stack & operator=(Stack const & other);
	
private:
	void stresize();
	
	type * data_;
	size_t size_;
	size_t counter_;
	
};

template <typename type>
Stack<type>::Stack() : 
		data_(new type[START_STACK_SIZE_]), 
		size_(START_STACK_SIZE_),
		counter_(0) {}

template <typename type>
Stack<type>::Stack(Stack<type> const & other) : 
		data_(new type[other.size_]),
		size_(other.size_),
		counter_(other.counter_)
{
	memcpy<type>(this->data_, other.data_, this->counter_);
}

template <typename type>
Stack<type>::~Stack()
{
	delete [] this->data_;
}

template <typename type>
bool Stack<type>::is_empty() const
{
	return !counter_;
}

template <typename type>
void Stack<type>::push(type data)
{
	if(counter_ == size_)
		this->stresize();
	data_[counter_++] = data;
}

template <typename type>
type Stack<type>::pop()
{
	if(!counter_)
		return 0;
	return data_[--counter_];
}

template <typename type>
void Stack<type>::stresize()
{
	data_ = resize<type>(data_, counter_, size_ * 2);
	size_ *= 2;
}

template <typename type>
Stack<type> & Stack<type>::operator = (Stack<type> const & other)
{
	size_ = other.size_;
	counter_ = other.counter_;
	delete [] data_, data_ = new type[size_];
	memcpy<type>(data_, other.data_, counter_);
	return *this;
}

template <typename type>
size_t Stack<type>::size()
{
	return counter_;
}
