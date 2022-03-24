#include<iostream>
#include <time.h>
using namespace std;
int n;
int Result[100][100];
int a[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int b[] = { 1, -1,  2, -2,  2, -2,  1, -1};
void init()
{
	cout<<"NHAPP SO LUONG HANG: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
	{
		Result[i][j]=0;
	}
}
	
}
void output()
{
		for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
	{
		cout<<Result[i][j]<<"  ";
	}
	cout<<endl;
}
}
int dem=1;
void Try(int i,int x,int y)
{
	if(i==n*n) {cout<<endl<<dem<<endl;
		output();cout<<endl<<"________________________";
		dem++;
	}
	else
	{
		int u,v,k;
		for( k=0;k<8;k++)
		{
			u=x+a[k];
			v=y+b[k];
			if(u>=0&&v>=0&&u<n&&v<n&&Result[u][v]==0)
			{
				Result[u][v]=i+1;
			Try(i+1,u,v);
				Result[u][v]=0;
			}
			
		}
		
	}
}
int main(){
init();
int x1,y1;
cout<<"nhap vi tri bat dau: \n";
cout<<"x= ";
cin>>x1;
cout<<"y= ";
cin>>y1;
double time_use;
	clock_t start, end;
Result[x1][y1]=1;
start = clock();
Try(1,x1,y1);	
end = clock();
time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time: %.2fs\n",time_use);



}
