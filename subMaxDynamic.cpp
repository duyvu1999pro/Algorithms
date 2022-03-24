
#include <iostream>
using namespace std;
int a[]={13,-15,2,18,4,8,0,-5,-8};
int s=1,e=1;
void subMax()
{
	int MaxS=a[1],MaxE=a[1],s1=1;
	for(int i=2;i<9;i++)
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


