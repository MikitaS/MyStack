#include <iostream>
#include "stack.hpp"
#include <string>


using namespace std;
const int StackSize = 1000000;

int testStackDestructor();
int testStack();
int testStackWithOperatorCopy();
int testStackWithConstructorCopy();
int testStackTopAccess();
int testStackEqualOperator();

int testStackWithOperatorCopy()
{
	Stack<int> exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	
	Stack<int> exp1;
	exp1 = exp;
	
	for(i = StackSize; i > 0; i--)
	{
		
		value = exp1.pop();
		if(value != i)
		{
			return 0;
		}
	}
	return 1;
}

int testStackWithConstructorCopy()
{
	Stack<int> exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	Stack<int> exp1(exp);
	
	for(i = StackSize; i > 0; i--)
	{
		value = exp1.pop();
		if(value != i)
		{
			return 0;
		}
	}
	return 1;
}

int testStack()
{
	Stack<int> exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	
	for(i = StackSize; i > 0; i--)
	{
		
		value = exp.pop();
		if(value != i)
		{
			return 0;
		}
	}
	return 1;
}

int testStackDestructor()
{
	Stack<int> exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	
	return 1;
}

int testStackTopAccess()
{
	Stack<string> exp;
	exp.push("hello");
	exp.push("test");
	exp.push("stack");

	if(exp.top() == "stack")
	{
		exp.top() = "passed";
		
		if(exp.pop() == "passed")
		{
			return 1;
		}
		
		else return 0;
	}
	return 0;
}

int testStackEqualOperator()
{
	Stack<int> exp1;
	
	exp1.push(1);
	exp1.push(2);
	exp1.push(3);
	exp1.push(4);
	
	Stack<int> exp2(exp1);
	
	if(exp1 != exp2)
		return 0;
		
	if(exp1 == exp2);
	else return 0;
	
	Stack<int> exp3;
	
	exp3.push(1);
	exp3.push(2);
	exp3.push(3);
	exp3.push(1);
	
	if(exp1 == exp3)
		return 0;
	
	
	return 1;
	
}

int main()
{
	if(testStack())
		cout <<  "+ stack test passed correct\n";
	else 
		cout << "- stack test failed\n";
	
	if(testStackWithOperatorCopy())
		cout <<  "+ copy operator test passed correct\n";
	else 
		cout << "- copy operator test failed\n";

	if(testStackDestructor())
		cout << "+ destructor's test done\n";
		
	if(testStackWithConstructorCopy())
		cout <<  "+ constructor copy test passed correct\n";
	else 
		cout << "- constructor copy test failed\n";
		
	if(testStackTopAccess())
		cout << "+ top access test passed correct\n";
	else
		cout << "- top access test failed\n"; 

	if(testStackEqualOperator())
		cout << "+ equal operator test passed correct\n";
	else
		cout << "- equal operator test failed\n"; 
	return 0;
}
