#include<bits/stdc++.h>
using namespace std;
int n,wt[102],pr[102],dp[102][52],dir[102][52],nt,amt;
int fun(int pos, int twt)
{
    int p=0,q=0;
    if(pos==n) return 0;
    if(dp[pos][twt]!=-1) return dp[pos][twt];
    if(twt+wt[pos]<=50) p = pr[pos]+fun(pos+1,twt+wt[pos]);
    q = fun(pos+1,twt);
    if(p>q)
    {
        dir[pos][twt]=1;
        dp[pos][twt]=p;
    }
    else
    {
        dir[pos][twt]=2;
        dp[pos][twt]=q;
    }
    return dp[pos][twt];
}
void cal(int pos, int twt)
{
    if(dir[pos][twt]==-1) return;
    if(dir[pos][twt]==1)
    {
        nt++;
        amt+=wt[pos];
        cal(pos+1,twt+wt[pos]);
    }
    else cal(pos+1,twt);
}
int main()
{
    int i,j,k,T;
    cin>>T;
    while(T--)
    {
        nt=0;
        amt=0;
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));
        cin>>n;
        for(i=0;i<n;i++) cin>>pr[i]>>wt[i];
        cout<<fun(0,0)<<" brinquedos"<<endl;
        cal(0,0);
        cout<<"Peso: "<<amt<<" kg"<<endl<<"sobra(m) "<<n-nt<<" pacote(s)"<<endl<<endl;

    }
}
