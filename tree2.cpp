#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node * left;
	node * right;
	node * parent;
	// constructor
	node (int value)
	{
		left=NULL;
		right=NULL;
		data=value;
		parent=NULL;
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
					if(curr->left==NULL){ node * temp= new node(value);
					curr->left=temp;
					temp->parent=curr;}
					else inserthelper(curr->left,value);
				}
			else 
				{
			// else move right and call inserthelper
					if(curr->right==NULL){ node * temp= new node(value);
					curr->right=temp;
					temp->parent=curr;}
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

	/*node* search(node*curr,int value)
		{
			// if the value found or reached end of tree
			if(curr==NULL || curr->data==value) return curr;
			else if(value < curr->data) return search (curr->left,value);
			else return search (curr->right,value);
		}*/
	bool search1(node*current,int value)
		{
			if(current==NULL)
				{
					return false;
				}
			else if(current->data==value)
				{
					return true;
				}
			else if(value>current->data) return search1(current->right,value);
			else if(value<current->data) return search1(current->left,value);
		}
	void search(int value)
		{
    			if(search1(root,value)==1)
    			cout<<endl<<"the element "<<value<<" is  found in the binary search tree  ";
    			else
        		cout<<" The element  "<<value<<" is not found  ";
		}
	node* findminimum(node * curr)
		{
			
			while(curr->left!=NULL)
				{
					curr=curr->left;
				}
			cout<< "the minimum value is"<<curr->data;
		}
	node* findmaxmum(node * curr)
		{
			while(curr->right!=NULL)
				{
					curr=curr->right;
				}
			cout<<"the maximum value is"<< curr->data;
			//if(curr->right==NULL) return curr;
				
		}
	int countitems()
		{
			return count(root);
		}
	int count(node*curr)
		{
			if(curr==NULL) return 0;
			else if(curr!=NULL)
			return 1+count(curr->left)+count(curr->right);
		}
	void replace(node * curr, int value)
		{
			node*rep=new node(value);
			replace1(curr,rep);
		}
	void replace1(node*curr,node*rep)
		{
			int a= rep->data;
			rep->data=curr->data;
			curr->data=a;
		}
	
	node* delete1(node*curr,int value)
		{
			if(root==NULL) return root;
			else if(value<curr->data)   curr->left=delete1(curr->left,value); 
			else if(value>curr->data)   curr->right=delete1(curr->right,value);
			else{
   			//desired element
    			//CASE-------1
   				 if(curr->left==NULL && curr->right==NULL)
					{
        			 delete curr;
       				 curr=NULL;
      				 return curr;
   					}
    			//CASE--------2
   				 else if(curr->left==NULL)
					{
        			 node*temp=curr;
        			 curr=curr->right;
        			 delete temp;
    					}

   				 else if(curr->right==NULL)
					{
        			 node*temp=curr;
        			 curr=curr->left;
       				 delete temp;
   					}
  			//CASE---------3
   				 else
					{
    				 node*temp=findminimum(curr->right);
   				 node*as=curr;
   				 curr->data=temp->data;
    				 curr->right=delete1(curr->right,temp->data);
  					}
			    }
  				 return curr;

		}
	void Delete(int value)
		{
			if( search1(root,value)==1)
			delete1(root,value);
			else
    			cout<<" entered no "<<value<<" is invalid"<<endl;
		}
	// to find the height of the binary search tree
	int maximum(int a,int b)
		{
			if(a>b)return b;
			else return a;
		}
	int height(node*current)
		{
			if(root==NULL) return 0;
			else if(current==NULL) return 0;
			else
				{
					// l - leftheight and r- right height
   				         int l=height(current->left)+1;
    				         int r=height(current->right)+1;

				}
		}
	void height()
		{
  			cout<<"  the height of tree is "<<height(root)<<endl;
		}

	//function to print the number between given range
	void rangeprint(int val1,int val2)
		{
			rangeprint1(val1,val2,root);
		}
	void rangeprint1(int value1,int value2,node*curr)
		{
	    		if(curr==NULL) return;
			if(curr->data>value1) rangeprint1(value1,value2,curr->left);
	   		if(value1<=curr->data && value2>=curr->data)
				{
	   		cout<<curr->data<< "  ";
	  			}
			if(value2>curr->data)
	   		rangeprint1(value1,value2,curr->right);

		}
	

	//function to count the leaf node of BST

	 int leafcount(node*curr)
		{
	 		if(curr==NULL)return 0;
			if(curr->right==NULL && curr->left==NULL) return 1;
			else return leafcount(curr->right)+leafcount(curr->left);
		}

	//function to print the data of leaf nodes of BST
	void leaf_datadisplay(node*curr)
		{
	//base case
			if(curr==NULL) return;
			else if(curr->right==NULL && curr->left==NULL)
				{
	   				 cout<<"  "<<curr->data<<"  ";
				}
			else
				{
	   				 leaf_datadisplay(curr->left);
	   				 leaf_datadisplay(curr->right);
				}

		}
	
};
int main()
{
binarysearch b1;
int b;
for(int i=0;i<7;i++)
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
b1.search(n);
/*if(b1.search(b1.root,n) != NULL)
        cout<<"The entered value  is FOUND"<<endl;
    else
        cout<<"The entered value  is NOT FOUND"<<endl;*/
/*b1.findminimum(b1.root);
cout<<endl;
b1.findmaxmum(b1.root);
cout<<endl;
cout<<b1.countitems();
cout<<endl;
int a;
cin>>a;
b1.Delete(a);
b1.display();
cout<<endl;
int c;
cin>>c;
b1.replace(b1.root,c);
b1.display();*/
b1.height();
cout<<"enter two number for printing the intermediate value present in the bst"<<endl;
int p,q;
cin>>p;
cin>>q;
b1.rangeprint(p,q);

cout<<endl<<"the number of leaf nodes is  "<<b1.leafcount(b1.root)<<endl;
cout<<"the data of leaf nodes are  :";
b1.leaf_datadisplay(b1.root);
return 0;
}
