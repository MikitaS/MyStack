#pragma once

template <typename type = int>
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

///Operators:
	Stack & operator=(Stack const & other);
	
private:
	type * data_;
	size_t size;
	
	const size_t START_STACK_SIZE = 50;
};
