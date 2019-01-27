#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
    // Inserts to the end of the linked list.
    void insert(int value){
        
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
    }
    // Displays the linked list.
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
    void InsertAt(int value, int pos)
	{
        // checking the position of the given value as this position exist or not
        if(CountItems()< pos-1)
   	{
            cout<<"the value can not inserted as that position does not exist"<< endl;
        }
	else{
        // reach the required position
        Node * current=head;
	int i=1;
    	while(i<pos-1)
	{
	i++;
	current=current->next;
	}
	// creating a new node
        Node * temp = new Node(value);
	// moving ptr to the inserting position
	temp->next=current->next;
	current->next=temp;
 	}
    }
    void DeleteAt(int pos)
    {
        // locate the required position
	if( CountItems()<pos)
	{
	   cout<<"the element does not exist"<< endl;
	}
        else
      {
	// finding the specific position which remain exist in the domain
	Node * current = head;
	Node * current1 ;
	int i=1;
	while(i<pos)
	{
        i++;
	current=current->next;
	}
	// shifting the second pointer towards the current 
        // findig the element placed before the deleting element
 	 current1=head;
	int r=1;
 	while((current1->next)->next !=head)
	{
	current1=current1->next;
	r++;
	} 
	// shifting the pointer
	current1->next=current->next;
	// deleting the current one
	delete current;
      }
    }
    void Delet()
    {
        // Deletes the last element.
	Node * current=head;
	Node * current1;
        while( current->next->next!=head){
	current=current->next;
	}
	current1=current->next;
	current->next=head;
	current1->next=NULL;
	// deleting the last one
	delete current1;
	
    }
    int CountItems(){
	int k=1;
	Node * current = head;
        // Counts the Number of items.
	while(current->next!=head){
	k++;
	current=current->next;
	}
	return k;
    }


};

int main(){
    CSLL csll1;
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
    //csll1.insert(1);
    csll1.display();
    csll1.InsertAt(2,9);
    csll1.display();
    csll1.InsertAt(9,1);
    csll1.display();
    csll1.Delet();
    csll1.display();
    csll1.DeleteAt(5);
    csll1.CountItems();
}
