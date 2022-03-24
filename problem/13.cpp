
#include <iostream>
using namespace std;
int a[]={13,-15,2,18,4,8,0,-5,-8};
int s=1,e=1;
void subMax()
{
	int MaxS=a[0],MaxE=a[0],s1=1;//maxS la kq chinh
	for(int i=1;i<9;i++)         //maxE la ban nhap
	{
		if(MaxE>0)                   
		MaxE=MaxE+a[i];                 
		else {
			MaxE=a[i];s1=i;
		}
		if(MaxE>MaxS)
		{
			MaxS=MaxE;e=i;s=s1;
		}
		
	}
	
}


int main()
{
 subMax();
 cout<<s+1<<" "<<e+1;
}


