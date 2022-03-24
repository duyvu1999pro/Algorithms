#include<iostream>
#define max 6
using namespace std;
int matrix[max][max];//[chiso doc][chi so ngang]
void show(int a[][6])
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
	{
		if(a[i][j]<10)
		cout<<" ";
		cout<<a[i][j]<<"   ";
	}
	cout<<endl;
	}
}
int min(int key[], bool mstSet[]) {
       int min = 99,k=0;
       for (int v = 0; v < 6; v++)
       {  if (mstSet[v] == true && key[v] < min)
             min = key[v], k = v;
}
        return k;
     }
void prim(int mat[][6])
{
	int closest[max];	int lowcost[max];
	bool free[max];     int i,j,k,Min;
	for(i=0;i<max;i++)
	{
		lowcost[i]=99;	closest[i]=-1;	free[i]=true;
	}	
	
	for(i=0;i<max-1;i++)
	{
		k=min(lowcost,free);
		free[k]=false;
		for(j=0;j<max;j++)
		{
			if(mat[k][j]<lowcost[j]&&mat[k][j]!=0&&free[j])
			{
				lowcost[j]=mat[k][j];
				closest[j]=k;
			}
		}
	}
		for(int temp=1;temp<max;temp++)	
		cout<<endl<<temp+1<<"->"<<closest[temp]+1;
	
}
int main(){
	int n=6,m=6;

matrix[0][1]=6;matrix[1][4]=3;
matrix[0][2]=1;matrix[1][5]=99;
matrix[0][3]=5;matrix[2][3]=5;
matrix[0][4]=99;matrix[2][4]=6;
matrix[0][5]=99;matrix[2][5]=4;
matrix[1][2]=5;matrix[3][4]=99;
matrix[1][3]=99;matrix[3][5]=2;matrix[4][5]=6;
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
prim(matrix);
\
}
