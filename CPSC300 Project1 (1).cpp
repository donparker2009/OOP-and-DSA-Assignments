//Don Parker
//CPSC 300 Project 1
//Creates an alphabetized linked-list of student records
//Contributions: Dr. David Robinson for original un-sorted linked list program

#include<iostream>
using namespace std;
struct student
    {
    string name;
    double gpa;
    int id;
    student *next;
    };
    
// Add a student (name, gpa, and id) to the list at head
void add_student
    (student *&head, string this_name, double this_gpa, int this_id)
    {
    student *tmp_p = new student;
    tmp_p->name = this_name;
    tmp_p->gpa = this_gpa;
    tmp_p->id = this_id;
    
    student *left, *right;
    
    if (!head) //Empty List
	{
    head = tmp_p;
    tmp_p->next = NULL;
	}	
	
	if (tmp_p->name < head->name) //New first in list.
	{
	tmp_p->next = head;
	head = tmp_p;
	}
	
	if (tmp_p->name > head->name)		
	{
		left = head;
		right = head->next;
		
		while (tmp_p->name > left->name )
		{
			if ( right == NULL ) //New end of list.
			{
			left->next = tmp_p;
			tmp_p->next = NULL;
			break;
			}
			if (tmp_p->name < right->name) //Middle element of list.
			{
			left->next = tmp_p;
			tmp_p->next = right;	
			break;
			}
			left = left->next;
			right = right->next;	
			
		}
	}
}
    
int main()
    {
    student *head = NULL, *tmp_p;
    string name;
    double gpa;
    int id;
    while (true)
        {
        cout << "name: ";
        cin >> name;
        if (name == "STOP")
            break;
        cout << "gpa: ";
        cin >> gpa;
        cout << "id: ";
        cin >> id;
        add_student (head, name, gpa, id);
        }
    cout << endl << "The list:\n";
    tmp_p = head;
    while (tmp_p != NULL)
        {
        cout << tmp_p->name;
        cout << ", gpa=" << tmp_p->gpa;
        cout << ", id=" << tmp_p->id << endl;
        tmp_p = tmp_p->next;
        }
    }
