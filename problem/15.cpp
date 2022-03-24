
#include <iostream>
using namespace std;
#define VC 999
#define n 6
int a[n][n]={0,20,15,VC,80,VC,
			 40,0,VC,VC,10,30,
			 20,4, 0,VC,VC,10,
			 36,18,15,0,VC,VC,
			 VC,VC,90,15,0,VC,
			 VC,VC,45,4,10, 0,
			};

int p[n][n];
void KQ(int dau,int cuoi)
{
	int temp_dau=dau,temp_cuoi=cuoi;
	if(p[temp_dau-1][temp_cuoi-1]!=0)
	{
	KQ(p[temp_dau-1][temp_cuoi-1],temp_cuoi);	
		KQ(temp_dau,p[temp_dau-1][temp_cuoi-1]);			
	}
	else
		cout<<"<--"<<temp_dau;

		
}
 void Floyd(int start,int end)
 {
 	int i,j,k;
 	int d[n][n];
 	
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			d[i][j]=a[i][j];
 			p[i][j]=0;
		 }
	 }
	 for(k=0;k<n;k++)//dinh 1 den n
	 {
	 	for(i=0;i<n;i++)//xet theo chieu doc 
	 	{//vd:dinh x den dinh 1
	 	
	 		if(d[i][k]>0&&d[i][k]<VC)//know dinh x
	 		{
	 			for(j=0;j<n;j++)//xet ngang 
	 			{
	 				//j ngang i doc k dinh
	 				if(d[k][j]>0&&d[k][j]<VC)//know dinh 1
	 				{       
	 					if(d[i][k]+d[k][j]<d[i][j])//lay 1 la dinh trung gian
					{
						d[i][j]=d[i][k]+d[k][j];
						p[i][j]=k+1;//luu dinh trung gian
						//nghia la i den j phai qua k
					}
					 }}}}}
					for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			
 			cout<<p[i][j]<<" ";
		 }
		 cout<<endl;
	 }
	 if(p[start-1][end-1]==0)
	 {
	 	cout<<"khong co duong di";
	 }
	 else
	 {
	 		 cout<<end;
	KQ(start,end);
	 }
	
 }

int main()
{

int start,end;
cout<<"(1,"<<n<<")\n";
cout<<"START: ";
cin>>start;
cout<<"END: ";
cin>>end;

Floyd(start,end);

}


