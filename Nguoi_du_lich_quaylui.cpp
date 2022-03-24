#include <iostream>
#define n 5
#define MAX 999
using namespace std;
int a[n],b[n],kq[n];
int KQ=MAX,temp=0;
int input[n][n]={
				0,1,2,7,5,
				1,0,4,4,3,
				2,4,0,1,2,
				7,4,1,0,3,
				5,3,2,3,0,
};
void init()
{
	for(int i=0;i<n;i++)
	b[i]=1;
}
void xuat()
{
	for(int i=0;i<n;i++)
	cout<<kq[i]+1;
	cout<<endl;
}
bool check()
{
for(int i=0;i<n-1;i++)
{
	if(input[a[i]][a[i+1]]==MAX)
return false;
}

return true;
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
			if(i==n-1&&check()==true) 
			{int k;
				temp=0;
				for(k=0;k<n-1;k++)
				{
					temp+=input[a[k]][a[k+1]];
				}
				
				if(temp<KQ)
				{KQ=temp;
				for(int k1=0;k1<n;k1++)
						kq[k1]=a[k1];
				}
				
			}
			else Try(i+1);
			b[j]=1;
		}
	}
}
int main()
{

init();
Try(0);	cout<<"cay khung nho nhat: COST="<<KQ<<endl;
xuat();
}

