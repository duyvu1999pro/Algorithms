#include <iostream>
using namespace std;
 int n1,m1;

void LCS(char X[],char Y[])
{
	int n=n1+1;
	int m=m1+1,i,j;
	
	int C[m][n];

	for(i=0;i<m;i++)
	C[i][0]=0;
	for(i=0;i<n;i++)
	C[0][i]=0;
	
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				C[i][j]=C[i-1][j-1]+1;
			
			}
			else
			{
				if(C[i-1][j]>=C[i][j-1])
				C[i][j]=C[i-1][j];
				else
				C[i][j]=C[i][j-1];
			}
		}
	}

for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{cout<<C[i][j]<<" ";
			}cout<<endl;}
j=m-1;
for(i=1;i<n;i++)
{
	if(C[m-1][i]==C[m-1][n-1])
	{
		while(C[j-1][i]==C[m-1][n-1])					
			j--;
				break;}}
char Result[100];
while(C[j][i]!=0)
{
	if(C[j-1][i]!=C[j][i]&&C[j][i-1]!=C[j][i])
	{
		Result[C[j][i]]=X[j-1];
		i--;j--;
	}
	else
	{
		while(1)
		{
			if(C[j][i-1]==C[j][i])
				i--;
			
			else if(C[j-1][i]==C[j][i])		
				j--;		
			else break;
		}	}	}
for(i=1;i<=C[m-1][n-1];i++)
cout<<Result[i];
}

int main()
{
	
//    char mang1[]={'H','O','A','H','O','N','G'};
//     char mang[]={'K','H','O','A','H','O','C'};
 // char mang[]={'K','H','U','Y','E','C','H',' ','T','R','U','O','N','G','T'};
 // char mang1[]={'T','R','O','N','G',' ','H','U','Y','E','C','H','K'};
    char mang1[]={'T','O','A','N','H','O','C'};
     char mang[]={'K','H','O','N','H','O','C'};
  n1=sizeof(mang)/sizeof(mang[0]);
   m1=sizeof(mang1)/sizeof(mang1[0]); 

//  char mang[100],mang1[100];
//  cout<<"nhhap chuoi 1: ";
//  cin>>mang; cout<<"nhhap chuoi 2: ";
//  cin>>mang1;
//  for(int i=0;i<100;i++)
//  {
//  	if(mang[i]=='.')
//  n1=i;
//  if(mang1[i]=='.')
//  m1=i;
//  }
  
 
  

  LCS(mang,mang1);
}


