#include<iostream>
#define max 10
using namespace std;
//int matrix[max][max]={0,3,5,2,6,
//					  3,0,6,7,3,
//					  5,6,0,5,4,
//					  2,7,5,0,1,
//					  6,3,4,1,0};
int matrix[max][max]={0,3,5,2,6,4,2,6,5,1,
					  3,0,6,7,3,4,9,5,1,7,
					  5,6,0,5,4,6,4,6,7,9,
					  2,7,5,0,1,5,6,1,1,6,
					  6,3,4,1,0,4,3,1,6,9,
					  4,4,6,5,4,0,1,6,8,2,
					  2,9,4,6,3,1,0,7,6,7,
					  6,5,6,1,1,6,7,0,5,6,
					  5,1,7,1,6,8,6,5,0,1,
					  1,7,9,6,9,2,7,6,1,0};
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
		for( k=0;k<max;k++)//tim dinh chua check
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
//	COST=COST+mat[v][0];
	return COST;
}
int main(){
	
     show(matrix); 
	 cout<<GTS(matrix);     
}
