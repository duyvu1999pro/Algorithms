//hanoitower
#include<iostream>
using namespace std;
void move(int n,char x, char y, char z)
{									   // X y Z  
	if(n==1) cout<<x<<"->"<<y<<endl;   // Z Y x
	else 
	{
		move(n-1,x,z,y);
		cout<<x<<"->"<<y<<endl;
		move(n-1,z,y,x);
	}
}
int main()
{
//	char a =
	move(10,'a','b','c');
}
