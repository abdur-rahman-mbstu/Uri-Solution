#include<bits/stdc++.h>
using namespace std;
int n,m,dam[1002],mana[1002],dp[1001][2101];
int fun(int pos, int tdam)
{
    int p=0,q=0;
    //cout<<pos<<" "<<tdam<<endl;
    if(pos==n)
    {
        if(tdam>=m) return min(p,q);
        else return 2000000;
    }
    if(dp[pos][tdam]!=-1) return dp[pos][tdam];
    if(tdam<m) p = mana[pos]+fun(pos+1,tdam+dam[pos]);
    q = fun(pos+1,tdam);
    return dp[pos][tdam] = min(p,q);
}
int main()
{
    int i,j,ans;
    while(cin>>n>>m)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; i++) cin>>dam[i]>>mana[i];
        ans=fun(0,0);
        if(ans==2000000) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
