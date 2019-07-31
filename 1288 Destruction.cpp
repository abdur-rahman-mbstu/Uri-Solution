#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[52][102],n,m,cap,tar,pr[55],wt[55];
int fun(int pos, int twt)
{
    int p=0,q=0;
    if(dp[pos][twt]!=-1) return dp[pos][twt];
    if(pos==n) return 0;
    if(twt+wt[pos]<=cap) p = pr[pos]+fun(pos+1,twt+wt[pos]);
    q = fun(pos+1,twt);
    return dp[pos][twt] = max(p,q);
}
int main()
{
    int T,t,i,j,pp;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++) cin>>pr[i]>>wt[i];
        cin>>cap>>tar;
        pp=fun(0,0);
        if(pp>=tar) cout<<"Missao completada com sucesso"<<endl;
        else cout<<"Falha na missao"<<endl;
    }
    return 0;
}
