#include<iostream>
#define max 5
using namespace std;
int matrix[max][max];
void show(int a[][max])
{
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
	{
		if(a[i][j]<10)
		cout<<" ";
		cout<<a[i][j]<<"   ";
	}
	cout<<endl;
	}
}
int GTS(int mat[][max])
{
	int i=0,min,k,v,w,COST=0;
	bool check[max];
	int TOUR[max];
	for(k=0;k<max;k++)
	check[k]=false;
	
	v=0;
	check[0]=true;
	TOUR[0]=v;
	
	while(i<max-1)
	{
		min=99;
		for( k=0;k<max;k++)
		{
			if(!check[k])
			{
				if(min>mat[v][k])
				{
					min=mat[v][k];
					w=k;
				}
			}
		}
		v=w;
		i++;
		TOUR[i]=v;
		check[v]=true;
		COST+=min;
		
	}
	COST=COST+mat[v][0];
	return COST;
}
int main(){
	int n=5;
matrix[0][1]=1;matrix[1][4]=3;
matrix[0][2]=2;
matrix[0][3]=7;matrix[2][3]=1;
matrix[0][4]=5;matrix[2][4]=2;
matrix[1][2]=4;
matrix[1][3]=4;matrix[3][4]=3;
for(int i=0;i<n;i++)
{
	matrix[i][i]=0;
}
for(int i=n;i>0;i--)
{
	for(int j=i-1;j>=0;j--)
	{
		matrix[i][j]=matrix[j][i];
	}
}
     show(matrix); 
	 cout<<GTS(matrix);     
}
