#include "iostream"
#define n 6
#define vc 99999
using namespace std;
//int c[n][n] = {
//	{vc,3,14,18,15},
//	{3,vc,4,22,20},
//	{17,9,vc,16,4},
//	{6,2,7,vc,12},
//	{9,15,11,5,vc}
//};
int c[n][n] = {
	{vc,20,15,vc,80,vc},
	{40,vc,vc,vc,10,30},
	{20,4,vc,vc,vc,10},
	{36,18,15,vc,vc,vc},
	{vc,vc,90,15,vc,vc},
	{vc,vc,45,4,10,vc}
};

int Cmin,f,S;
int daxet[50],x[50];
void init(){
	int i,j;
	Cmin = vc;
	for(i=0 ; i<n ; i++)
		daxet[i] = 0;
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++){
			if(Cmin > c[i][j]){
				Cmin = c[i][j];
			}		
		}
	f = vc;
	S = 0;
	x[0] = 0;
}

void Try(int i){
	int j,Tong,g;
	for(j=1 ; j<n ; j++){
		
		if(daxet[j] == 0){
			x[i] = j;
			daxet[j] = 1;
			S += c[x[i-1]][x[i]];
			
				if(i==n-1)
					{
					Tong = S + c[x[n-1]][x[0]];
						if(Tong < f){
								f = Tong;		
								system("cls");				//truy vet//
								cout<<"1";
										for(int i=1 ; i<n ; i++){
											cout<<"-->"<<x[i]+1;
											}							//truy vet//
									}
					}
					
				else{
					g = S + (n-i)*Cmin;
						if(g <= f){
							Try(i+1);
							}
					}
					
			S -= c[x[i-1]][x[i]];
			daxet[j] = 0;
			
		}
		
		
	}
	
}
int main(){
	init();
	Try(1);
	cout<<"\nCOST = "<<f;
}
