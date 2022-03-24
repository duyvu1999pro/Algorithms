#include<iostream>
#define N 6
#define INFINITE 99
using namespace std;
int mang[N][N]={	         0,      20,      15,INFINITE,		80,INFINITE,
					        40,       0,INFINITE,INFINITE,		10,		 30,
					        20,       4,       0,INFINITE,INFINITE,	  	 10,
					        36,      18,      15,       0,INFINITE,INFINITE,
					  INFINITE,INFINITE,      90,      15,		 0,INFINITE,
					  INFINITE,INFINITE,      45,		4,		10,		  0,
					 
					  };

void show(int a[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
	{
		if(a[i][j]<10)
		cout<<" ";
		cout<<a[i][j]<<"   ";
	}
	cout<<endl;
	}
}
void xuatdd(int s,int k,int ddnn[])
{
	int i;
	cout<<endl<<s+1<<"->"<<k+1<<" : \n";
	i=k;
	while(i!=s)
	{
		cout<<i+1<<"<--";
		i=ddnn[i];
	}
	cout<<s+1;
}
void Dijkstra( int s1)
{
	
	int L[N];
	bool check[N];
	int Result[N];
	int i,s=s1-1,k,min,dht;
	for(i=0;i<N;i++)
	{
		check[i]=false;
		L[i]=INFINITE;
	}
	check[s]=true;
	L[s]=0;
	dht=s;
	int count=1;
	while(count<=N-1)
	{
		min=INFINITE;
		for(i=0;i<N;i++)
		{
			if(check[i]==false)
			{
				if(L[dht]+mang[dht][i]<L[i])//tim duong di nho hon
				{
					L[i]=L[dht]+mang[dht][i];
					Result[i]=dht;
				}
				if(L[i]<min)//tim dinh gan nhat
				{
					min=L[i];
					k=i;
				}
			}
			
		}
		xuatdd(s,k,Result);
		cout<<"\nTrong so: "<<L[k];
		dht=k;
		check[dht]=true;
		count++;
		
	}// Result[-,3,1,6,2,3]
	//      L[-,19,15,29,29,25]
}
int main(){


      show(mang);    	
          Dijkstra(1);
           
}
