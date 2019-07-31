#include<bits/stdc++.h>
using namespace std;
int n,cap,ti[50],nm[50],dp[35][602];
int knap(int pos, int wt)
{
    if(pos==n) return 0;
    int p=0,q=0;
    if(dp[pos][wt]!=-1) return dp[pos][wt];
    if(wt+nm[pos]<=cap) p = ti[pos]+knap(pos+1,wt+nm[pos]);
    q = knap(pos+1,wt);
    dp[pos][wt] = max(p,q);
    return dp[pos][wt];
}
int main()
{
    int i,j;
    while(cin>>n&&n)
    {
        cin>>cap;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++) cin>>ti[i]>>nm[i];
        cout<<knap(0,0)<<" min."<<endl;
    }
    return 0;
}
