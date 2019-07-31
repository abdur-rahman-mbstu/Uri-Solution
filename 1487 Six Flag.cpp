#include<bits/stdc++.h>
using namespace std;
int n,ttm,d[102],pnt[102],dp[102][700];
int fun(int pos, int sm)
{
    int pp=0,qq=0;
    if(pos==n) return 0;
    if(dp[pos][sm]!=-1) return dp[pos][sm];
    if(sm+d[pos]<=ttm) pp = pnt[pos]+fun(pos,sm+d[pos]);
    qq = fun(pos+1,sm);
    return dp[pos][sm]=max(pp,qq);
}
int main()
{
    int i,j,k,T,t=1;
    while(cin>>n>>ttm&&n)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++) cin>>d[i]>>pnt[i];
        cout<<"Instancia "<<t++<<endl<<fun(0,0)<<endl<<endl;
    }
}

