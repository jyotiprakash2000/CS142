#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node * left;
	node * right;
	// constructor
	node (int value)
	{
		left=NULL;
		right=NULL;
		data=value;
	}
};

class binarysearch
{
public:
	node * root;
	binarysearch()
		{
			root=NULL;
		}
	void insert(int value)
		{
			inserthelper(root, value);
		}
	void inserthelper(node * curr, int value)
		{
			// base case if curr is null ,insert there
			//node * temp=new node(value);
			if(curr==NULL)
				{
					curr=new node(value);
					if(root==NULL) root=curr;	
					return;
				}
			// else compare the curr data with value
			else if(value< curr->data)
				{
			// if curr data < value -> move left and call inserthelper
					if(curr->left==NULL) curr->left= new node(value);
					else inserthelper(curr->left,value);
				}
			else 
				{
			// else move right and call inserthelper
					if(curr->right==NULL) curr->right= new node(value);
					else inserthelper(curr->right,value);
				}
		}
	void display()
		{
			display2(root);
		}
	void display2(node*curr)
		{
			//base condition
			if(curr==NULL) return;
			// display left
			display2(curr->left);
			// display current
			cout << curr->data <<",";
			// display right
			display2(curr->right);
		}
	//node displayfancy( int spaces);

	node* search(node*curr,int value)
		{
			// if the value found or reached end of tree
			if(curr==NULL || curr->data==value) return curr;
			else if(value < curr->data) return search (curr->left,value);
			else return search (curr->right,value);
		}
};
int main()
{
binarysearch b1;
int b;
for(int i=0;i<10;i++)
{cin>>b;
b1.insert(b);}
/*b1.insert(3);
b1.insert(23);
b1.insert(9);
b1.insert(5);*/
b1.display();
cout<<endl;
int n;
cin>>n;

if(b1.search(b1.root,n) != NULL)
        cout<<"The entered value  is FOUND"<<endl;
    else
        cout<<"The entered value  is NOT FOUND"<<endl;
return 0;
}
