#include <iostream>
#define n 3
using namespace std;
int a[n],b[n];
void init()
{
	for(int i=0;i<n;i++)
	b[i]=1;
}
void xuat()
{
	for(int i=0;i<n;i++)
	cout<<a[i]+1;
	cout<<endl;
}
void Try(int i)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(b[j]==1)
		{
			a[i]=j;
			b[j]=0;
			if(i==n-1) xuat();
			else Try(i+1);
			b[j]=1;
		}
	}
}
int main()
{
init();
Try(0);
}


