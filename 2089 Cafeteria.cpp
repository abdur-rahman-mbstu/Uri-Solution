#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,p,q,dp[100002];
    while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        while(n--)
        {
            cin>>p;
            for(i=m-p;i>=0;i--)
            {
                dp[i+p] = dp[i]+dp[i+p];
            }
        }
        if(dp[m]) cout<<"sim"<<endl;
        else cout<<"nao"<<endl;
    }
}
