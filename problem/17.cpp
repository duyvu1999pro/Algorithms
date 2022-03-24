#include<iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int m;
int n;
int Result[100][100];
int a[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int b[] = { 1, -1,  2, -2,  2, -2,  1, -1};
void init()
{
	cout<<"NHAPP SO LUONG HANG m= ";
	cin>>m;
	cout<<"NHAPP SO LUONG COT n= ";
	cin>>n;
	for(int i=0;i<m;i++)
	{
			for(int j=0;j<n;j++)
	{
		Result[i][j]=0;
	}
}
	
}
void output()
{
		for(int i=0;i<m;i++)
	{
			for(int j=0;j<n;j++)
	{
		if(Result[i][j]<10)
		cout<<" "<<Result[i][j]<<"  ";
		else
		cout<<Result[i][j]<<"  ";
	}
	cout<<endl;
}
cout<<endl<<"________________________";//exit(0);
}

int dem=1;
void Try(int i,int x,int y)
{
	if(i==m*n) {cout<<endl<<"TH "<<dem<<" :"<<endl;
		output();
		dem++;
	}
	else
	{
		int u,v,k;
		for( k=0;k<8;k++)
		{
			u=x+a[k];
			v=y+b[k];
			if(u>=0&&v>=0&&u<m&&v<n&&Result[u][v]==0)
			{
				Result[u][v]=i+1;
			Try(i+1,u,v);
				Result[u][v]=0;
			}
			
		}
		
	}
}
int main(){
	//1. m=3 n=4 x=1 y=1
	//2. m=5 n=5 x=3 y=3
	//3. m=3 n=8 x=1 y=1
	//4. m=4 n=5 x=1 y=1
	//5. m=5 n=5 x=2 y=2
	//6. m=3 n=15 x=1 y=1
init();
int x1,y1;
cout<<"nhap vi tri bat dau: \n";

while(1)
{
	cout<<"(x<="<<m<<")   x= ";
	cin>>x1;
	if(x1<=m)
	break;
}
while(1)
{
	cout<<"(y<="<<n<<")   y= ";
	cin>>y1;
	if(y1<=n)
	break;
}

x1=x1-1;y1=y1-1;
Result[x1][y1]=1;

double time_use;
	clock_t start, end;
start = clock();
Try(1,x1,y1);	
end = clock();
time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nTime: %.2fs\n",time_use);



}
