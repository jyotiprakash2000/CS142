#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head;
    DLL(){
        head = NULL;
    }
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != NULL)
               { current = current->next;}
            current->next = temp;
            temp->prev = current;    
        }
    }
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
    void InsertAt(int value, int pos){
        // creating a node
    Node * raja = new Node(value);
        // determing the required position
    Node * current=head;
    int i=0;
    while(i< pos-2){
    i++;
    current=current->next;
    }
        // moving the ptr to that position
        // link the node forward
    raja->next=current->next;
    current->next=raja;
        // link the node backward way
    raja->next->prev=raja;
    raja->prev=current;
    
    }
    void DeleteAt(int pos){
        // condition to delete a particular position
    if( countItems()<pos ){
    cout<<" The element does not exist"<< endl;
    }
    else {
if (pos==1){ 
    Node * current=head;
    head=current->next;
    current->next->prev=NULL;
    delete current;
    }
       // for another position except first one
    else{
      
       // finding that element
    Node * current =head;
    int a=1;
    while(a<pos){
    a++;
    current=current->next;
    }
       // defining another ptr to reach before the deleting one
    int b=1;
    Node * currentA = head;
    while(b<pos-1){
    b++;
    currentA= currentA->next;
    }

       // shifting the ptr
    currentA->next=current->next;
    current->next->prev=currentA;
       // delete the required position
    delete current;
    }
}
    }
    void Del(){
        // Deletes the last element.
        // store the last element as raja
    Node * current= head;
    Node * current1;
        // reach at last element
    while( (current->next)->next!= NULL){
    current=current->next;
    }
    current1=current->next;
    current->next=NULL;
    current1->prev=NULL;
        //update last element
    
        //delete last  element
    delete current1;
    }
    int countItems(){
        // Counts the Number of items remain
    int k=1;
        // before last element point to null
    Node * current = head;
    while ( current-> next != NULL){ 
    current= current->next;
    k++;
    } 
    return k;
    }

};

int main(){
    DLL dll1;
    for(int i= 1; i < 11; i++){
        dll1.insert(i);
    }
    dll1.display();
    dll1.InsertAt(5,3);
    dll1.display();
    dll1.Del();
    dll1.display();
    dll1.DeleteAt(8);
    dll1.display();
    cout << dll1.countItems()<< endl;
    return 0;
}
