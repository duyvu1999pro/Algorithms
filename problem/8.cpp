#include<iostream>
#define max 6
using namespace std;
int matrix[max][max]={
       						  0,6,1,5,99,99,
       						  6,0,5,99,3,99,
       						  1,5,0,5,6,4,
       						  5,99,5,0,99, 2,
       						  99,3,6,99, 0, 6,
							  99,99,4,2,6, 0,	};//[chiso doc][chi so ngang]


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
	
	for(i=0;i<max-1;i++)//chay so lan = so dinh
	{
		k=min(lowcost,free);//13642
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

show(matrix);
prim(matrix);
\
}
