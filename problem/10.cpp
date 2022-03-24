#include <iostream>
#define max 100
using namespace std;
//
//struct PT{
//    string MSV;
//    string MaM;
//};

void MangDinh(int n,int dinh[])
{
    for(int i=1;i<=n;i++)
    {
        dinh[i]=i;
    }
}
void BacDinh(int a[][max],int n,int bac[])
{
    for(int i=1;i<=n;i++)
    {
        bac[i]=0;
        for(int j=1;j<=n;j++)
        {
            bac[i]+=a[i][j];
        }
    }
}
void SortDinh(int dinh[],int bac[],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bac[i]<bac[j])
            {
                swap(bac[i],bac[j]);
                swap(dinh[i],dinh[j]);
            }
        }

    }
}

void ToMau(int a[][max],int dinh[],int n,int x[],int &sm)
{
    for (int i = 1;i <= n;i++)
    {
        if (x[dinh[i]] == 0)
        {
            sm++;
            x[dinh[i]] = sm;
            for (int j = i + 1;j <= n;j++)
            {
                if (a[dinh[i]][dinh[j]] == 0 && x[dinh[j]] == 0)
                {
                    int kt = 1;
                    for (int k = i + 1;k < j;k++)
                    {
                        if (a[dinh[k]][dinh[j]] == 1 && x[dinh[i]] == x[dinh[k]])
                        {
                            kt = 0;
                            break;
                        }
                    }
                    if (kt)
                    x[dinh[j]] = sm;
                }
            }
        }
    }
}
void xuatkq(int x[],int dinh[],int sm,int n)
{
    for (int i = 1;i <= sm;i++)
    {
        cout << "Mau " << i << ": ";
        for (int j = 1;j <= n;j++)
            if (x[dinh[j]] == i) cout << j << " ";
                cout << endl;
    }
}
int main()
{
  
    int bac[max];
    int dinh[max];
    int n=6;
    int x[n+1];
    {
        for(int i=1;i<=n;i++)
            x[i]=0;
    }
    int sm=0;
    
    int a[max][max]={
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,1,1,1,0},
        {0,1,1,0,0,1,0},
        {0,0,1,0,0,1,1},
        {0,0,1,1,1,0,1},
        {0,0,0,0,1,1,0}
    };
    BacDinh(a,n,bac);
    MangDinh(n,dinh);
    SortDinh(dinh,bac,n);
    for(int i=1;i<=n;i++)
    {
        cout<<dinh[i]<<"\t"<<bac[i]<<endl;
    }
    ToMau(a,dinh,n,x,sm);
    xuatkq(x,dinh,sm,n);

    return 0;
}
