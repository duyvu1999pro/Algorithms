#include <iostream>
#define n 7

using namespace std;

int a[n][n]={
				0,0,0,1,0,1,1,
				0,0,1,1,0,0,0,
				0,1,0,1,0,1,0,
				1,0,1,0,0,0,0,
				0,0,0,0,1,1,0,
				1,0,0,0,1,0,0,
				1,0,0,1,0,0,0,
};
int check[n];
int s1,t;
int result[n];
void input()
{
	for(int i=0;i<n;i++)
	check[i]=0;
	cout<<"nhap dinh bat dau: ";
	cin>>s1;
	s1=s1-1;
	cout<<"nhap dinh ket thuc: ";
	cin>>t;
	t=t-1;
	
}
void print()
{
	cout<<t+1<<" <-- ";
	int k=result[t];
	while(k!=s1)
	{
		cout<<k+1<<" <-- ";
		k=result[k];
	}
	cout<<s1+1<<endl;
	
}
 void DFS(int s)
 {
 	int u;
 	check[s]=1;
 for(u=0;u<n;u++)
 {
 	if(a[s][u]==1&&check[u]==0)
 	{
 		result[u]=s;
 		if(u!=t)
 		DFS(u);
 	
 		else
 		print();
 		check[u]=0;
	 }
 }
 
      }
int main()
{
input();
DFS(s1);
}

