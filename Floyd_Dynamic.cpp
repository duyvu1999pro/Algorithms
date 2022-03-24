
#include <iostream>
using namespace std;
#define VC 999
#define n 6
int a[n][n];
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
a[0][0]=0;  a[0][1]=20;a[0][2]=15;a[0][3]=VC; a[0][4]=80;a[0][5]=VC;
a[1][0]=40; a[1][1]=0; a[1][2]=VC;a[1][3]=VC; a[1][4]=10;a[1][5]=30;
a[2][0]=20; a[2][1]=4; a[2][2]=VC; a[2][3]=VC; a[2][4]=VC;a[2][5]=10;
a[3][0]=36; a[3][1]=18;a[3][2]=15; a[3][3]=0;  a[3][4]=VC;a[3][5]=VC;
a[4][0]=VC; a[4][1]=VC; a[4][2]=90; a[4][3]=15; a[4][4]=0;a[4][5]=VC;
a[5][0]=VC; a[5][1]=VC;a[5][2]=45; a[5][3]=4;  a[5][4]=10;a[5][5]=00;
int start,end;
cout<<"(1,"<<n<<")\n";
cout<<"START: ";
cin>>start;
cout<<"END: ";
cin>>end;

Floyd(start,end);

}


