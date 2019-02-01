//#include<iostream>
#include "Rj2.cpp"
using namespace std;
class stack 
{
 public:
 Node * top;
 linkedlist l1;
 stack()
	{
	top=l1.head;
	}
	//pushes on top
	void push(int value)
	{
		// void insertat(intvalue,int pos)
		l1.insertAt(1,value);
		//top=new head
		top=l1.head;
	}
	// pops the top
	void pop()
	{
		// void deleteat(int pos)
		l1.deletAt(1);
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
stack s1;
for(int i=0;i<5;i++)
{s1.push(i);}
s1.display();
s1.pop();
s1.display();
s1.pop();
s1.display();
s1.size();
s1.display();
return 0;
}
