
#include <iostream>
using namespace std;
struct object{int W,C; };
int Bag_Best(int n,int b,object *a)
{
	int L=0,i=0;
	int MaxV[n+1][b+1];
		for(L=0;L<=b;L++ )
			MaxV[0][L]=0;	
			
		for(i=0;i<=n;i++ )
			MaxV[i][0]=0;
		
			for(i=1;i<=n;i++)	
		{
				for(L=1;L<=b;L++ )
			{
				MaxV[i][L]=MaxV[i-1][L];
				if(   (  L  >=  a[i].W  )  && (  MaxV[i-1][L-a[i].W]  +  a[i].C  >  MaxV[i-1][L]  )    )
				MaxV[i][L]=MaxV[i-1][L-a[i].W]+a[i].C;
			}
		}
		int x=n,y=b,Cost=MaxV[n][b];
		while(1)
		{
			cout<<x<<" + ";
			y=y-a[x].W;
			Cost=Cost-a[x].C;
			for(i=0;i<=x;i++)
			{
				if(MaxV[i][y]==Cost)
				{
					x=i;break;
				}
			}
		
			if(Cost==a[x].C)
			{cout<<x<<endl;break;}
		}
		return MaxV[n][b];
}

int main()
{
 	object mang[7];
 	mang[1].C=7; mang[1].W=3;
 	mang[2].C=10;mang[2].W=4;
 	mang[3].C=20;mang[3].W=5;
 	mang[4].C=19;mang[4].W=7;
 	mang[5].C=13;mang[5].W=6;
 	mang[6].C=40;mang[6].W=9;
 	cout<<Bag_Best(6,19,mang);
 
}


