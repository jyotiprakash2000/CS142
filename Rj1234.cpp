//#include<iostream>
#include "Rj2.cpp"
using namespace std;
class queue
{
 public:
 Node * top;
 linkedlist l1;
 queue()
	{
	top=l1.head;
	}
	//pushes on top
	void enqueue(int value)
	{
		// void insertat(intvalue,int pos)
		l1.insertAt(1,value);
		//top=new head
		top=l1.head;
	}
	// pops the top
	void dequeue()
	{
		// void deleteat(int pos)
		l1.delet();
		//top=new head;
		top=l1.head;
		
	}
	//empty or not

	bool isempty()
	{
	if(top==NULL) return true;
	return false;
	}
	//size
	int size()
	{
		return l1.countItems();
		
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
r1.dequeue();
r1.display();
	
return 0;
}
