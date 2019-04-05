#include<iostream>
using namespace std;
class binaryheap
	{
		public:
		int*arr;
		int cap;
		int heapsize;
		int root;
		binaryheap(int capacity)
			{
				int cap=capacity;
				arr= new int[capacity];
				root=0;
				heapsize=0;
			}
		int right(int i)
			{
				return 2*i+2;
			}
		int left(int i)
			{
				return 2*i+1;
			}
		int parent(int i)
			{
				return (i-1)/2;
			}
		void swap(int*a,int*b)
			{
		int x=*a;
		*a=*b;
		*b=x;
			}
	void heapify(int i)
		{

			int l=left(i);
			int r=right(i);
			int smallest=i;
			if(l<=heapsize && arr[i]>arr[l])
			smallest=l;
			if(r<=heapsize && arr[smallest]>arr[r])
			    smallest=r;
			if(smallest!=i)
				{
					swap(&arr[i],&arr[smallest]);
					heapify(smallest);
				}
		}
//function to insert element
	void  insert(int value)
		{
			if(heapsize>=cap)
				{
				    cout<<"OVER FLOW"<<endl;
				    return;
    				}
			heapsize++;
			int i=heapsize-1;
  			arr[i]=value;
 			while(i!=0 && arr[i]<arr[parent(i)])
				{
				    swap(&arr[i],&arr[parent(i)]);
				    i=parent(i);
  				}
		}
	void decrease(int i,int newval)
		{
			arr[i]=newval;
			while(i!=0 && arr[i]<arr[parent(i)])
				{
		   			swap(&arr[i],&arr[parent(i)]);
		   			i=parent(i);
				}
		}
	//extract minimum
	int extractmin()
		{
			if(heapsize<=0) {return 0;}
			if(heapsize==1)
				{
	   				heapsize--;
	 				return arr[0];
				}
			int root=arr[0];
	   		arr[0]=arr[heapsize-1];
	   		heapsize--;
	   		heapify(0);
	   		return root;
	        }
	void Delete(int i)
		{
			if(heapsize!=0)
				{
   					 decrease(i,-1);
  					 heapify(i);
   					 extractmin();
				}
		}
	void display()
		{
			for(int i=0;i<heapsize;i++)
				{
   					 cout<<arr[i]<<"  ";
				}
			cout<<endl;
		}
};


int main()
	{
		binaryheap b1(1000);
		for(int i=10;i>0;i--)
			{
				b1.insert(i);
			}
		b1.display();
		/*for(int j=0;j<b.heapsize;j++){
		    cout<<b.arr[j];
		}*/
		cout<<endl;
		cout<<b1.extractmin()<<endl;
		cout<<endl;
		b1.display();
		b1.Delete(5);
		b1.display();
		b1.display();
		return 0;
}

