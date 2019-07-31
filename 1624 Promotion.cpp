#include<bits/stdc++.h>
using namespace std;
int n,m,cap,pr[103],wt[103],dp[102][3005];
int fun(int pos, int sm)
{
    if(dp[pos][sm]!=-1) return dp[pos][sm];
    if(pos>=n) return 0;
    int pp=0,qq=0;
    if(sm+wt[pos]<=cap) pp = pr[pos]+fun(pos+1,sm+wt[pos]);
    qq = fun(pos+1,sm);
    return dp[pos][sm] = max(pp,qq);
}
int main()
{
    int p,q,T,i;
    while(cin>>n&&n)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++) cin>>pr[i]>>wt[i];
        cin>>cap;
        p = fun(0,0);
        cout<<p<<endl;
    }
}
