//Queue using linked list


#include <iostream>
using namespace std;

class node	//class node that contain data value and link to the next node
{
	public:
		int data;
		node *next;
};

class list : public node //class list -> child class of node
{
	public:
		node *lstptr;	//pointer that points to the 1st node
		node *temp;		//pointer that points to the last node and hold temporary value of the node
		list ()	//default constructor
		{
			lstptr = NULL;	//initialising lstptr and temp to NULL
			temp = NULL;
		}
		
		void enqueue()	//function for insert at end
		{
			cout << "\n\n\tENQUEUE\n\n";
			
			int value;
			node *newnode = new node();
			node *temp1;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != NULL; temp1 = temp1->next);	//traversing till last node
				temp1->next = newnode;	//creating link between newnode and last node
				newnode->next = NULL;
				cout << "Node added successfully";
			}
		}
		
		void dequeue()	//function to delete from rear
		{
			cout << "\n\n\tDEQUEUE\n\n";
			
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				temp1 = lstptr;
				lstptr = lstptr->next;	//pointing lstptr to next node
				cout << "Deleted node had : " << temp1->data;
				delete temp1;
			}
		}
		
		void print_lnkdlst()	//function to print whole linked list
		{
			cout << "\n\n\tPRINT STACK\n\n";
			
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "Queue is empty.";
			}
			else
			{
				cout << "Elements in the Stack : ";
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					cout << temp1->data << " ";		//printing each value of stack
				}
			}
		}
};

void choice(list lst)	//function for user choice
{
	int ch;	//choice variable for user
	
	cout << "\n\n\nChoose one of the following:\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\nEnter your choice : ";
	cin >> ch;
	switch(ch)
	{
		case 1 :
			{
				lst.enqueue();
				choice(lst);
				break;
			}
			
		case 2 :
			{
				lst.dequeue();
				choice(lst);
				break;
			}
			
		case 3 :
			{
				lst.print_lnkdlst();
				choice(lst);
				break;
			}
		
		case 4 :
			{
				exit(0);
				break;
			}
			
		default :
			{
				cout << "\nChoice not valid.";
				choice (lst);
			}
	}
}

main ()
{
	list lst;
	choice(lst);
}
