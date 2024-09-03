#include <iostream>
#define MAXSIZE 3
using namespace std;

//Circular Queue
int cQueue[MAXSIZE] , rear = -1 , front = -1 ;

int insert()
{
	int element;
	if (front == ((rear + 1) % MAXSIZE))
	{
		cout<<"Circular Queue is full"<<endl;
	}
	else
	{
		rear = (rear + 1 ) % MAXSIZE;
		if (front == -1)
		{
			front = 0;
		}
		cout<<"Enter the element you want to insert :: ";
		cin>>element;
		cQueue[rear] = element; 
		cout<<"The Element "<<element<<" is inserted at "<<rear<<" position"<<endl;
	}
	return 0;
}

int del()
{
	if ((front == -1) || (front > rear))
	{
		cout<<"Queue is Empty"<<endl;
	}
	else
	{
		int element = cQueue[front];
		front = (front + 1) % MAXSIZE;
		cout<<"The element "<<element<<" has been deleted from the queue"<<endl;
		
		if (rear == (MAXSIZE - 1) && (front == 0) || (front > rear))
		{
			front = -1;
			rear = -1;
		}
	}
	
	return 0;
}

int display()
{
	if ((front == -1) || (rear == -1))
	{
		cout<<"The Queue is empty";
	}
	else
	{
		cout<<"The contents in the queue are :: ";
		for (int i = front ; i <= rear ; i++)
		{
			cout<<cQueue[i]<<" , ";
		}
		cout<<endl;
	}
	return 0;
}

int main()
{
	int choice = 1;
	while(choice != 4)
	{
		cout<<"1. Insert \t 2. Delete \t 3. Diplay \t 4. Exit \n";
		cout<<"Enter a number to perform the desired operation :: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1 :
				insert();
				break;
				
			case 2 :
				del();
				break;
				
			case 3 :
				display();
				break;
			
			case 4 :
				break;
			
			default :
				cout<<"Enter a valid choice"<<endl;
				break;
		}
	}
	if (choice == 4)
	{
		cout<<"Exit"<<endl;
	}
	return 0;
}
