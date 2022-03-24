#include<iostream>

using namespace std;
struct work
{
	int a,b;
};
int n=9;
void input(int &n,work a[])
{
	cout<<"nhap so cv: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"cong viec thu "<<i+1<<": \n";
		cout<<"time start: ";
		cin>>a[i].a;
		cout<<"time end: ";
		cin>>a[i].b;
	}
}
void swap(work &a,work &b)
{
	work temp=a;
	a=b;
	b=temp;
}
void sort(work c[],int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
	{
		if(c[j].a<c[i].a)
		{
			swap(c[j],c[i]);
		}
	}
	}	
}
void sort(work c[],int m,int m1)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
	{
		if(c[j].b<c[i].b)
		{
			swap(c[j],c[i]);
		}
	}
	}	
}
void sort(work c[],int m,int m1,int m2)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
	{
		if((c[j].b-c[j].a)<(c[i].b-c[i].a))
		{
			swap(c[j],c[i]);
		}
	}
	}	
}
void show(work c[],int m)
{
for(int i=0;i<m;i++)
	{
		cout<<"[ "<<c[i].a<<" - "<<c[i].b<<" ]";
	}
}
bool check(work x,work y)
{
	if(y.a>=x.b||x.a>=y.b)
	return false;//ko trung
	else return true;
}
bool check1(work x,int m,work s[])
{
	for(int i=0;i<m;i++)
	{
		if(check(x,s[i])==true)
		return false;
	}
	return true;
}

int main(){
work C[1000],S[1000];
//input(n,C);
C[0].a=1;C[0].b=8;
C[1].a=2;C[1].b=5;
C[2].a=6;C[2].b=9;
C[3].a=13;C[3].b=17;
C[4].a=7;C[4].b=10;
C[5].a=10;C[5].b=15;
C[6].a=13;C[6].b=19;
C[7].a=19;C[7].b=25;
C[8].a=7;C[8].b=12;
while(1)
{
	int temp;
cout<<"\n1. xeplich1\n2. xeplich2\n3. xeplich3\n";
cin>>temp;
if(temp==1)
sort(C,1);
if(temp==2)
sort(C,1,1);
if(temp==3)
sort(C,1,1,1);
show(C,9);
int m=0;
for(int i=0;i<n;i++)
	{
	if(check1(C[i],m,S)==true)// ko trung cai nao
	{
		S[m]=C[i];
		m++;
	}
	}
cout<<endl;
show(S,m);

}


}
