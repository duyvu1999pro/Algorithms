
#include <iostream>
using namespace std;
int BS(int a[],int x,int l,int r)
{
	if(l>r)
	return -1;
		int tg= (l+r)/2;
		 if(x>a[tg])
			BS(a,x,tg+1,r);
		else if(x<a[tg])
			BS(a,x,l,tg);
		else return tg;

}
int MIN(int a[],int l,int r)
{
	if(l==r) return a[l];
	else
	{
		int m=(l+r)/2;
		int ML=MIN(a,l,m);
		int MR=MIN(a,m+1,r);
		if(ML<MR)
		return ML;
		else return MR;
	}
}
int MAX(int a[],int l,int r)
{
	if(l==r) return a[l];
	else
	{
		int m=(l+r)/2;
		int ML=MAX(a,l,m);
		int MR=MAX(a,m+1,r);
		if(ML>MR)
		return ML;
		else return MR;
	}
}
int main()
{
   int a[]={3,5,8,9,4,2,7,5,3,9,8};
   //cout<<BS(a,14,0,6);
   cout<<MAX(a,000,6 );
   
  
}


