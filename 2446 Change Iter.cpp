#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,i,j,c,mx,dp[100002],n,p,a[1002];
    while(cin>>p>>n)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=0; i<n; i++) cin>>a[i];
        for(i=0;i<n;i++)
        {
            for(j=p;j>=a[i];j--) dp[j] = dp[j]+dp[j-a[i]];  //Number of ways
        }
        //cout<<dp[p]<<endl;
        if(dp[p]) cout<<"S"<<endl;
        else cout<<"N"<<endl;
    }
}
