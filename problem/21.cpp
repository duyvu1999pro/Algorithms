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
 void BFS(int s)//s la dinh bat dau
 {
 int u,j,dauQ=0,cuoiQ=0;//u la ban nhap cua s
 int queue[1000];
 queue[cuoiQ]=s;//khoi tao dau queue = dinh bat dau
check[s]=1;//s da dc xet
while(dauQ<=cuoiQ)//duyet tu dau queue den cuoi queue
{
	u=queue[dauQ];//u= dau queue

	dauQ++;//dau queue tang 1 don vi
	for(j=0;j<n;j++)//duyet tat ca cac dinh
	if(a[u][j]==1&&check[j]==0)//neu u den j ton tai va chua xet
	{
		cuoiQ++;//cuoi queue ++
		queue[cuoiQ]=j;//cuoi queue= dinh j
		check[j]=1;//j da dc xet 
		result[j]=u;//luu kq
		if(j==t)
		print();
		
	}

}
      }
int main()
{
input();
BFS(s1);
}

