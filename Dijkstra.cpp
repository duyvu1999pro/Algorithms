#include<iostream>
#define N 6
#define INFINITE 99
int mang[N][N];
using namespace std;
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

for(int i=0;i<6;i++)
mang[i][i]=0;
mang[0][1]=20;mang[0][2]=15;		mang[0][3]=INFINITE;	mang[0][4]=80;			mang[0][5]=INFINITE;
mang[1][0]=40;mang[1][2]=INFINITE;  mang[1][3]=INFINITE;	mang[1][4]=10;			mang[1][5]=30;
mang[2][1]=4;mang[2][0]=20;			mang[2][3]=INFINITE;	mang[2][4]=INFINITE;	mang[2][5]=10;
mang[3][1]=18;mang[3][2]=15;		mang[3][0]=36;			mang[3][4]=INFINITE;	mang[3][5]=INFINITE;
mang[4][1]=INFINITE;mang[4][2]=90;  mang[4][3]=15;			mang[4][0]=INFINITE;	mang[4][5]=INFINITE;
mang[5][1]=INFINITE;mang[5][2]=45;  mang[5][3]=4;			mang[5][4]=10;			mang[5][0]=INFINITE;
      show(mang);    	
          Dijkstra(1);
           
}
