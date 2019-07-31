#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[105],n,p,q,dp[10052][102];
bool flag;
int fun(int sm, int pos)
{
    //cout<<sm<<" "<<pos<<endl;
    int pp=0,qq=0;
    if(dp[sm][pos]!=-1) return dp[sm][pos];
    if(pos>=n)
    {
        if(sm==q) return 1;
        else return 0;
    }
    pp = fun(sm+a[pos],pos+1);
    qq = fun(sm,pos+1);
    return dp[sm][pos] = pp+qq;
}
int main()
{
    int m,i,j,x,y,sm,t=1;
    while(cin>>x>>y>>n)
    {
        if(x==0&&y==0&&n==0) break;
        memset(dp,-1,sizeof(dp));
        flag=0;
        sm = x+y;
        if(x<y) swap(x,y);
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            sm+=a[i];
        }
        cout<<"Teste "<<t++<<endl;
        if(sm&1) cout<<"N"<<endl<<endl;
        else
        {
            p = sm/2;
            q = p-x;
            m = fun(0,0);
            //cout<<m<<endl;
            if(m==0) cout<<"N"<<endl<<endl;
            else cout<<"S"<<endl<<endl;
        }
    }
    return 0;
}
