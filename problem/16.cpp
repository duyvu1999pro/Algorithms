
#include <iostream>
using namespace std;
int a[20],n,b[50],c[50],x[20];
void init()
{
	cout<<"NHAPP SO LUONG HANG: ";
	cin>>n;
	for(int i=2;i<=2*n;i++)
	b[i]=1;
		for(int i=1-n;i<=n-1;i++)
	c[i]=1;
		for(int i=1;i<=n;i++)
	a[i]=1;
	
}
void output()
{
	for(int i=1;i<=n;i++)
	cout<<"{"<<i<<","<<x[i]<<"}";
	cout<<endl;
}
int dem=1;
void tim(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(a[j]&&b[i+j]&&c[i-j])
		{
			a[j]=0;b[i+j]=0;c[i-j]=0;
			x[i]=j;
			if(i==n){cout<<dem<<endl;
			 output();dem++;
			 }
			else tim(i+1);
			a[j]=1;b[i+j]=1;c[i-j]=1;
		}
	}
}
int main()
{
init();
tim(1);
cout<<c[-1];
}


