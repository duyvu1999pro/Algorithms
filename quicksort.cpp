
#include <stdio.h>
#include <iostream>
using namespace std;   

void hoanvi(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
void in(int *a)
{
	for(int i=0;i<10;i++)
	cout<<a[i]<<" ";
}
void quicksort(int	*a,int l,int r)  
{                                                     					
	if(l<=r)                          
	{                                 
		int i=l; int j=r;                         
		int key=a[(l+r)/2];     
		cout<<"| key= "<<key<<"|";         
		while(i<=j)                      
		{                                
		 while(a[i]<key)   i++;          
		 while(a[j]>key)    j--;                           
		   if(i<=j)                      
	    	{                            
	        	hoanvi(&a[i],&a[j]); 
				 cout<<"| "<<a[i] <<" swap "<<a[j]<<endl;
				 in(a);          
	         	i++;
	        	j--;
	        }
		}
	  if(l<j) quicksort(a,l,j);
	  if(r>i) quicksort(a,i,r);
	}
}


int main()
{
	int a[]= {3,4,1,4,5,8,9,11,2,7};
	in(a);
	quicksort(a,0,9);
	
}
