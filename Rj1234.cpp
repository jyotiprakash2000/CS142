//this is a library
#include <iostream>
using namespace std; 

class Node
{
	public:
	//data
	int data;

	//pointer to the next Node
	Node * next;
	//construct that makes the ptr to NULL
	Node()
        {
	   next=NULL;
        }
};
class linkedlist
{
	//  head + circles inside linked with eachother
public:
	// Head-> Node type ptr
Node * head;
Node * tail;
	//construct
	linkedlist()
{
	head=NULL;
	tail=NULL;
}
	// circles inside linked with eachother
	//Rules how circles will be linked

	// insert
	void insert(int value)
{
	// if 1st Node is added
	 Node * temp= new Node;
	//insert value in the Node
	temp->data = value;
	//1st Node only.
	if(head== NULL)
    {
	  head = temp;
	 
    }
	//anyother node only.
	else 
    {
	tail->next = temp;
	
    }
	tail = temp;

}
      void insertAt( int pos ,int value)
{
	Node * temp=new Node;
	temp->data=value;
	if(pos==1)
	{
	 if(head==NULL)
		{
		head=temp;
		tail=temp;
		}
	else
		{
		Node * current=head;
		temp->next=current;
		head=temp;
		}
	}
}

	
	        // deletion of last element
                void delet()
        {
                //store the tail in temp
                Node * temp = tail;
                // before tail has to point to null
                Node * current =head;
	         while( current->next != tail)
             {
                current=current->next;
             }
                
        
                current->next = NULL;
                //update tail
                tail = current;
                //delete temp
                delete temp;
        }
    //Deletion at some position
    void deletAt(int pos){
        //condition to delete a particular position
        if(countItems()<pos){
            cout<<"Element does not exist"<<endl;
        }
        else
        {
            //deleting the same position 1
            if(pos==1){
                Node * current = head;
                head= current->next;
                delete current;
            }
            else
            {
        //finding element to delete at that position 
        Node * current = head;
        int i =1;
        while(i < pos){
            i++;
            current = current->next;
        }
        //shift pointer to the before Node
        //find element before delete element
        Node * current1 = head;
        int j =1;
        while(j < pos-1){
            j++;
            current1 = current1->next;
        }
        //shifting
        current1->next = current->next;
        //delete current
        delete current;
            }
        }
    }
    //count the remainig items
    int countItems(){
        int i=1;
        // before tail has to point to null
        Node * current = head;
        while(current->next != NULL){
            current = current->next;
            i++;
        }
        return i;
    }
	                                     // display
	                                     void display()
                             {
                                             Node * current =head;
	                                     while( current != NULL)
                                      {
                                             cout << current->data<< "->";
                                             current=current->next;
                                      }
                                             cout <<" NULL" << endl;
                             }
};

int main()
{
linkedlist l1;
for(int i=0;i<10;i++)
	{l1.insert(i);
	}
l1.display();
l1.delet();
l1.display();
l1.insertAt(5,3);
l1.display();
l1.deletAt(6);
l1.display();
cout<<l1.countItems()<<endl;



}
