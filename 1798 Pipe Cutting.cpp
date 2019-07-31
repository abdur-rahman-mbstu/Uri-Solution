#include<bits/stdc++.h>
using namespace std;
int n,m,sz[1002],pr[1002],dp[1002][2004];
int fun(int pos, int sm)
{
    int pp=0,qq=0;
    if(pos==n) return 0;
    if(dp[pos][sm]!=-1) return dp[pos][sm];
    if(sm+sz[pos]<=m) pp = pr[pos]+fun(pos,sm+sz[pos]);
    qq = fun(pos+1,sm);
    return dp[pos][sm]=max(pp,qq);
}
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++) cin>>sz[i]>>pr[i];
        cout<<fun(0,0)<<endl;
    }
}



