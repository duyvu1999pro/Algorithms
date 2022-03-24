#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void exchange(int *mang,int i,int j,int m)
{
	for(int p=0;p<m;p++)
	swap(mang[i+p],mang[j+p]);
	
}
void tranpose(int mang[],int n,int m)
{
	int i=m;int j=n-m;
	while(i!=j)
	{
			if(i>j)
	{
		exchange(mang,m-i,m,j);
		i=i-j;
	}
	else if(i<j)
	{
	j=j-i;
		exchange(mang,m-i,m+j,i);
	}
	}

	exchange(mang,m-i,m,i);
}
void print(int mang[],int n)
{
	for(int i=0;i<n;i++)
	cout<<mang[i]<<"  ";
}
int main(){
int n=15;int m;
     int mang[] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
     cout<<"nhap so phan tu can hoan doi:\n";
     cin>>m;
    tranpose(mang,n,m);
    
    print(mang,15);
   


}
