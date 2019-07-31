#include<bits/stdc++.h>
using namespace std;
struct info
{
    int p,q,w;
}in[100];
int par[100];
bool cmp(info a, info b)
{
    return a.w<b.w;
}
int fnd(int r)
{
    if(par[r]==r) return r;
    else return par[r]=fnd(par[r]);
}
int mst(int n, int m)
{
    int i,a,b,sm=0,cnt=0;
    for(i=1;i<=n;i++) par[i]=i;
    for(i=0;i<m;i++)
    {
       a = fnd(in[i].p);
       b = fnd(in[i].q);
       if(a!=b)
       {
           par[a]=b;
           cnt++;
           sm+=in[i].w;
           if(cnt==n-1) break;
       }
    }
    return sm;
}
int main()
{
    int n,m,i,j;
    while(cin>>n>>m)
    {
        for(i=0;i<m;i++)
        {
            cin>>in[i].p>>in[i].q>>in[i].w;
        }
        sort(in,in+m,cmp);
        cout<<mst(n,m)<<endl;
    }
    return 0;
}
