#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1000002];
int main()
{
    int T,t,i,j,p,n,coin[30],tar;
    cin>>T;
    while(T--)
    {
        cin>>n>>tar;
        for(i=0; i<n; i++) cin>>coin[i];
        sort(coin,coin+n);
        if(tar%coin[n-1]==0)
        {
            cout<<tar/coin[n-1]<<endl;
            continue;
        }
        for(i=0; i<1000001; i++) dp[i]=2000000;
        dp[0]=0;
        for(i=0; i<n; i++)
        {
            p = coin[i];
            for(j=p; j<=tar; j++) dp[j] = min(dp[j],dp[j-p]+1);
        }
        cout<<dp[tar]<<endl;
    }
    return 0;
}

