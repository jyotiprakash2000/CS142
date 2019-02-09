

//#include<iostream>
#include "LLwm.cpp"
using namespace std;
class queue
{
 public:
 Node * front;
 Node * end;
 linkedlist l1;
 queue()
	{
	front=l1.head;
	end=l1.tail;
	}
	//pushes on top
	void enqueue(int value)
	{
		// void insertat(int pos,int value)
		l1.insertAt(1, value);
		//top=new head
		front=l1.head;
	}
	// pops the top
	void dequeue()
	{
		// void delete(int pos)
		l1.delet();
		//top=new head;
		end=l1.tail;
		
	}
	//empty or not

	bool isempty()
	{
	if(front==NULL) return true;
	return false;
	}
	//size
	int size()
	{
		return l1.countItems();
		
	}
	void enddisplay()
	{
	if(l1.head==NULL)
		{
		cout<<"the queue has no element to display"<<endl;
		}
	else
		{
		cout<<" the end element is:"<<l1.head->data<<endl;
		}
	}
		void frontdisplay()
	{
	if(l1.tail==NULL)
		{
		cout<<"the queue has no element to display"<<endl;
		}
	else
		{
		cout<<" the front element is:"<<l1.tail->data<<endl;
		}
	}
	
	void display()
	{
	l1.display();
	}
};
int main()
{
queue r1;
for(int i=0;i<6;i++)
{r1.enqueue(i);}
r1.display();
r1.dequeue();
r1.display();
r1.dequeue();
r1.display();
r1.dequeue();
r1.display();
r1.dequeue();
r1.display();
r1.dequeue();
r1.display();
cout<<r1.size()<<endl;
r1.enddisplay();
r1.frontdisplay();
r1.dequeue();
r1.display();
//r1.dequeue();
//r1.display();
cout<< r1.isempty();
cout<<endl;	
return 0;
}

