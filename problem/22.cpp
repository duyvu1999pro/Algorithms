#include <iostream>
#include <conio.h>
#define MAX 100

using namespace std;

struct DoVat 
{
	int w;
	int c;
};

void nhap(DoVat dv[], int &n){
	int i;
	for (i=0; i< n; i++)
	{
		cout<<"nhap do vat thu: "<<i+1<<endl;
		cout<<"w = "; cin>>dv[i].w;
		cout<<"c = "; cin>>dv[i].c;
	}
}

//void truyvet(DoVat dv[], int MaxV[MAX][MAX], int b, int n){
//	int i;
//	int l = b;
//	cout<<"cac vat duoc chon la: "; 
//	for(i = n; i > 0; i--){
//		if (MaxV[i][l] != MaxV[i-1][l])
//		{
//			cout<<i<<"\t";
//			l -= dv[i].w;
//		}
//		if(MaxV[i][l] == 0){};
//	}
//}

void CaiTui(DoVat dv[], int b, int n){
	
	int MaxV[MAX][MAX];
	int l, i;
	for (i=0; i<n; i++) MaxV[i][0] = 0;
	for (l = 0; l < b ; l++) MaxV[0][l] = 0;

	for( i =1; i< n; i++)
		for( l = 1; l<b; l++){
			MaxV[i][l] = MaxV[i-1][l];
			if((l>=dv[i].w) && (MaxV[i-1][l-dv[i].w] + dv[i].c > MaxV[i-1][l]))
				MaxV[i][l] = MaxV[i-1][l-dv[i].w] + dv[i].c;
		}
		l = b;
		cout<<"cac vat duoc chon la: "; 
		for(i = n-1; i > 0; i--){
			if (MaxV[i][l] != MaxV[i-1][l])
			{
				cout<<i<<"\t";
				l -= dv[i].w;
			}
			if(MaxV[i][l] == 0){};
		}	
	//cout<<n;
	//truyvet(dv,MaxV,b,n);
	
}



int main(){
	int n, b;
	DoVat dv[100];
	//int MaxV[MAX][MAX];
	cout<<"nhap dung luong cai tui: "; cin>>b;
	cout<<"nhap so do vat: "; cin>>n;
	nhap(dv,n);
	CaiTui(dv, b, n);
	//truyvet(dv, MaxV, b, n);
	_getch();
}