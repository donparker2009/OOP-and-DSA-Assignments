//Don Parker
//CPSC 200 Project 4
//A program that manages a stack and a queue.

#include<iostream>
using namespace std;

const int MAX = 4;
char stack[MAX];
char queue[MAX];
int sp;
int put_ptr;
int get_ptr;

// ======== Stack Functions ========

// Initialize the stack.
void stack_init()
{
	sp = -1;
}

// Push c onto the stack.
void push(char c)
{
	sp++;
	stack[sp] = c;
}

// Pop and return one item from the stack.
char pop()
{
	char item; 
	sp--;
	item = stack[sp + 1];
	return item;
	
}

// ======== Queue Functions ========

// Initialize the queue.
void queue_init()
{
	put_ptr = -1;
	get_ptr = -1;
}

// Add c to the queue.
void put(char c)
{
	put_ptr = (put_ptr + 1) % MAX;
	queue[put_ptr] = c;
	
}

// Remove and return one item from the queue.
char get()
{
	char item;
	get_ptr = (get_ptr + 1) % MAX;
	item = queue[get_ptr];
	return item;
}

int main()
{
	stack_init();
	queue_init();
	
	while(true)
	{
		int choice;
		
		cout << "1. Push a character onto the stack.\n"
			 << "2. Pop a character from the stack.\n"
			 <<	"3. Add a character to the queue.\n"
			 <<	"4. Remove a character from the queue.\n";
			 
		cin >> choice;
		
		if (choice == 1)
		{
			char c;
			cout << "Enter a character: ";
			cin >> c;
			push(c);
		}
		if (choice == 2)
		{
			if (sp > -1)
				{
					if (sp < MAX)
						cout << "You popped the character " << pop() << endl;
				}
			else
			{
				cout << "Empty Stack\n";
			}
		}
		if (choice == 3)
		{
			char c;
			cout << "Enter a character: ";
			cin >> c;
			put(c);
		}
		if (choice == 4)
		{
			if (put_ptr != get_ptr)
			{
				//not working correctly: if ((get_ptr + 1) < put_ptr)
					cout << "You removed the character " << get() << endl;
			}
			else
			{
				cout << "Empty Queue\n";
			}
		}
	}
	
	
	return 0;
}
