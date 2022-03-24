#include<iostream>
using namespace std;
//bool check()
//{
//	
//}
//void sudoku(int i)
//{
//	if(mang[][]==0)
//  	{
//	   for(int j=1;j<=9;j++)
//	   {
//		
//			mang[][]=j;
//		if(check(mang[][])==true)
//		{
//				if(i==80)
//					Xuat
//				else
//					sudoku(i+1);
//		}
//	
//		
//		
//     	}	
//	}
//	else
//	sudoku(i+1);
//	
//}'
int mang[9][9]={0,1,0,0,0,0,8,7,0
               ,0,0,0,0,4,1,6,0,3
			   ,0,0,0,7,0,0,0,0,0
			   ,0,0,0,0,8,5,0,0,0
			   ,1,3,0,4,0,9,0,5,8
			   ,0,0,0,1,6,0,0,0,0
			   ,0,0,0,0,0,6,0,0,0
			   ,4,0,2,5,1,0,0,0,0
			   ,0,8,9,0,0,0,0,3,0};
bool checkValid(int S[][9], int x, int y, int k){
    for(int i = 0; i <9 ; i++){
        if(S[x][i] == k) return false;
    }
    for(int i = 0; i <9 ; i++){
        if(S[i][y] == k) return false;
    }
    int a = x/3, b = y/3;
    for(int i = 3*a; i < 3*a+3; i++){
        for(int j = 3*b; j < 3*b+3; j++){
            if(S[i][j] == k) return false;
        }
    }
    return true;
}
void print(int S[][9])
{
	for(int i=0;i<9;i++)
	{
			for(int j=0;j<9;j++)
	{
		cout<<mang[i][j]<<"  ";
	}
	cout<<endl;
	}
}

void solveSudoku(int S[][9], int x, int y){
    if(y == 9){
        if(x == 8){
            print(S);
            exit(0);
        } else {
            solveSudoku(S, x+1,0);
        }
    } else if(S[x][y] == 0){
        for (int k = 1; k <=9; k++){
            if(checkValid(S,x,y,k)){
                S[x][y] = k;
                solveSudoku(S, x, y+1);
                S[x][y] = 0;
            }
        }
    } else {
        solveSudoku(S,x,y+1);
    }
}


int main(){

        solveSudoku(mang,0,0);       
			 
}
