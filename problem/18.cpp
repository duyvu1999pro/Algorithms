#include <iostream>
#define n 5
using namespace std;
struct dovat{
	int w,c;
};
int a[n],b[n];
int k;
int Max=0;int temp=0;
void input()
{
	cout<<"nhap khoi luong cai tui: ";
	cin>>k;
}
bool check(dovat mang[])
{
	int tong=0;temp=0;
	 for(int m=0;m<n;m++)
			 {
			 	if(a[m]==1)
			 	{
			 		tong+=mang[m].w;
			 		temp+=mang[m].c;
				 }
			 	
				 }	
				 if(tong>k) return true;
				 else return false;
}
void xuat()
{
	for(int i=0;i<n;i++)
{
	if(b[i]==1)
	cout<<"do vat "<<i+1<<"+";
}
}
void Try(int i,dovat mang[])
{
	int j;
	for(j=0;j<=1;j++)
	{
	a[i]=j;
		if(i<n-1)
			Try(i+1,mang);
		else 
			{
			if(check(mang)==false)
			{
				if(temp>Max)
				{
					Max=temp;
					 for(int m=0;m<n;m++)
			 {
			 	b[m]=0;
			 		if(a[m]==1)
			 	b[m]=1;
			 }
				 } 
			
			}
			}
	}
}
int main()
{
input();
dovat mang[5];
mang[0].c=7;mang[0].w=10;
mang[1].c=4;mang[1].w=2;
mang[2].c=5;mang[2].w=4;
mang[3].c=2;mang[3].w=14;
mang[4].c=12;mang[4].w=8;
Try(0,mang);
xuat();
cout<<endl<<Max;
}


