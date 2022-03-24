
#include <stdio.h>
#include <iostream>

using namespace std;   
int n;
void hoanvi(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
void in(int *a)
{
	for(int i=0;i<=n;i++)
	cout<<a[i]<<" ";
}
void quicksort(int	*a,int l,int r)  
{                                                     					
	if(l<=r)                          
	{                                 
		int i=l; int j=r;                         
		int key=a[(l+r)/2];     
		cout<<" | key= "<<key<<"|";         
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
{	  //  int a[]= {3,4,1,6,5,8,9};n=6;	
	//int a[]= {3,4,1,4,5,8,9,11,2,7,12,6};n=11;
	int a[]= {3,4,1,4,5,8,7,11,2,36,24,12};n=11;														//1.
//	int a[]=   {3,1,7,8,2,6,9,14,26,19,54,72,31};n=12;													//2.
//	int a[]={794,411,160,1,950,887,468,253,674,27,584,521,214,535,428,613,594,91};n=17;					//3.
//	int a[]={592,993,870,47,764,61,138,315,64,768,905,702,565,24,484};n=14;								//4.
//	int a[]={354,235,300,266,3,347,424,857,286,175,96,581,234,165,336,505};n=15;						//5.
in(a);
	quicksort(a,0,n);
		
	
}
