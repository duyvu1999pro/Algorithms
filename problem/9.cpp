#include<iostream>
# define DINH_MAX 7
using namespace std;
struct Edge{
	int x,y,c;
};
void swap(Edge &x,Edge &y)
{
	Edge temp=x;
	x=y;y=temp;
}
void sort(Edge mang[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mang[j].c<mang[i].c)
			swap(mang[j],mang[i]);
		}
	}
}
void show(Edge mang[],int n)
{
	cout<<"cac canh them vao: ";
	for(int i=0;i<n;i++)
	{
		cout<<endl<<mang[i].x<<"->"<<mang[i].y;
	}
}
void Kruskal(Edge mang[],int n)
{
	sort(mang,n);
	int check[DINH_MAX+1];
	int result=0;
	Edge RESULT[100];
		for(int i=1;i<DINH_MAX+1;i++)
			check[i]=i;
		
	for(int i=0;i<n;i++){
		if(check[mang[i].x]!=check[mang[i].y])//neu phu thuoc dinh khac nhau
		{
			RESULT[result]=mang[i];   // chon canh nay`
			result++;
			int temp=check[mang[i].y];
		for(int j=1;j<DINH_MAX+1;j++)
		{
			if(check[j]==temp)//nhung dinh co phu thuoc =phu thuoc dinh dinh den
			check[j]=check[mang[i].x];//bang phu thuoc dinh toi (co ca dinh den)
		}
//		cout<<endl;
//		for( int k=1;k<DINH_MAX+1;k++)
//			cout<<" "<<check[k];
		}
	}
		
	show(RESULT,result);
}

int main(){
int n=12;
Edge mang[n];
mang[0].x=1;mang[0].y=4;mang[0].c=1;
mang[1].x=1;mang[1].y=2;  mang[1].c=3;
mang[2].x=1;mang[2].y=6;  mang[2].c=3;
mang[3].x=2;mang[3].y=6;  mang[3].c=6;
mang[4].x=2;mang[4].y=3;  mang[4].c=4;
mang[5].x=3;mang[5].y=5;  mang[5].c=7;
mang[6].x=3;mang[6].y=4;  mang[6].c=3;
mang[7].x=3;mang[7].y=7;  mang[7].c=5;
mang[8].x=4;mang[8].y=5;  mang[8].c=6;
mang[9].x=4;mang[9].y=6;  mang[9].c=2;
mang[10].x=5;mang[10].y=6;mang[10].c=5;
mang[11].x=6;mang[11].y=7;mang[11].c=1;
Kruskal(mang,n);


}
