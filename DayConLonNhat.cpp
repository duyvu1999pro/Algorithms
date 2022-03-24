#include<iostream>

using namespace std;


int MaxRightVector(int a[], int i, int j,int &temp){
	int maxSum=a[i], sum=a[i];
	for(int k=i+1; k<=j; k++){
		sum+=a[k];
		if(sum>maxSum){
			maxSum=sum;
			temp=k;
		
		} 
	}
	return maxSum;
}
void show(int a[],int i,int j)
{
	for(int k=i;k<=j;k++)
	{
		cout<<a[k]<<" ";
	}
}
int MaxLeftVector(int a[], int i, int j,int &temp){
	int maxSum=a[j], sum=a[j];
	for(int k=j-1; k>=i; k--) {
		sum+=a[k];
		if(sum>maxSum) {
			maxSum=sum;temp=k;		
		} 
	}
	return maxSum;
}
int findMax(int a, int b) {
	int max=a>b?a:b;
	return max;
}
int findMax(int a, int b, int c){
	int max=c>findMax(a,b)?c:findMax(a,b);
	return max;
}
int v1=0,u1=0;	
int MaxSubVector(int a[], int i, int j){
	if(i==j) return a[i];
	else {
		int m=(i+j)/2;
		int u=0,v=0;
		int wl= MaxSubVector(a,i,m);
		int wr=MaxSubVector(a,m+1,j);
		int wm= MaxLeftVector(a,i,m,v)+ MaxRightVector(a,m+1,j,u);
		if(findMax(wl,wr,wm)==wm)
		{		v1=v;u1=u;}
		return findMax(wl,wr,wm);
	}
}

int main() {
	int a[]={-98,54,67,65,-879,78,65,21,-6,67};
	show(a,0,9);cout<<endl;
	cout<<"sum ="<<MaxSubVector(a,0,9)<<endl;
//	cout<<v1<<" "<<u1<<endl;
cout<<"mang con lon nhat: \n";	show(a,v1,u1);

	return 0;
}


