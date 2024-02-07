//Don Parker
//CPSC 200 Project 5
//A program that manages a stack object and two queue objects.

#include<iostream>
#include<cstdlib>
using namespace std;

class Stack
{
	public:
		void push(char c); // Push c onto the stack.
		char pop(); // Pop and return one item from the stack.
		int size(); // Returns current number of items on the stack.
		Stack(); // Constructor initializing pointer.
		
	private:
		int sp;
		char stack[1000];
		
};

void Stack::push(char c)
{
	sp++;
	stack[sp] = c;
}

char Stack::pop()
{
	char item; 
	sp--;
	item = stack[sp + 1];
	return item;
}

int Stack::size()
{
	return sp + 1;
}

Stack::Stack()
{
	sp = -1;
}

class Queue
{
	public:	
		void put(char c); // Add c to the queue.
		char get(); // Remove and return one item from the queue.
		int size(); // Returns current number of items in the queue.
		Queue(); // Constructor initializing pointers.
		
	private:
		int put_ptr;
		int get_ptr;
		char queue[1000];
};

void Queue::put(char c)
{
	put_ptr = (put_ptr + 1) % 1000;
	queue[put_ptr] = c;
}

char Queue::get()
{
	char item;
	get_ptr = (get_ptr + 1) % 1000;
	item = queue[get_ptr];
	return item;
}

int Queue::size()
{	
	if ( put_ptr < get_ptr )
		return 1000 - ((get_ptr + 1) - (put_ptr + 1));
	else 
		return put_ptr - get_ptr;
}

Queue::Queue()
{
	put_ptr = -1;
	get_ptr = -1;
}

int main()
{	
	Stack only;
	Queue first;
	Queue second;
	
	while (true)
	{
		int choice;
		
		cout << "1. Push a character onto the stack.\n"
			 <<	"2. Pop a character from the stack.\n"
			 <<	"3. Size of the stack.\n"
			 <<	"4. Add a character to the first queue.\n"
			 <<	"5. Remove a character from the first queue.\n"
			 <<	"6. Size of the first queue.\n"
			 <<	"7. Add a character to the second queue.\n"
			 <<	"8. Remove a character from the second queue.\n"
			 <<	"9. Size of the second queue.\n";
			 
		cin >> choice;
		
		if (choice == 1)
		{
			char c;
			cout << "Enter a character: ";
			cin >> c;
			only.push(c);
		}
		if (choice == 2)
		{
			
			cout << "You popped the character " << only.pop() << " from the stack.\n";
	
		}
		if (choice == 3)
		{
			cout << "The current size of the stack is " << only.size() << endl;
		}
		if (choice == 4)
		{
			char c;
			cout << "Enter a character: ";
			cin >> c;
			first.put(c);
		}
		if (choice == 5)
		{
			cout << "You removed the character " << first.get() << " from the first queue.\n";
		}
		if (choice == 6)
		{
			cout << "The size of the first queue is " << first.size() << endl;
		}
		if (choice == 7)
		{
			char c;
			cout << "Enter a character: ";
			cin >> c;
			second.put(c);
		}
		if (choice == 8)
		{
			cout << "You removed the character " << second.get() << " from the second queue.\n";
		}
		if (choice == 9)
		{
			cout << "The size of the second queue is " << second.size() << endl;
		}
	}

	return 0;
}
