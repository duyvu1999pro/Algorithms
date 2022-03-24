#include <iostream>
#define n 3
using namespace std;
int a[n];

void xuat()
{
	for(int i=0;i<n;i++)
	cout<<a[i];
	cout<<endl;
}
void Try(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
	a[i]=j;
		if(i<n-1)
			Try(i+1);
		else 
			xuat();
	}
}
int main()
{

Try(0);
}


