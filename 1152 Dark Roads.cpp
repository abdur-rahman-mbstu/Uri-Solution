#include<bits/stdc++.h>
using namespace std;
struct info
{
    int u,v,w;
}in[200004];
bool cmp(info a, info b)
{
    return a.w<b.w;
}
int par[200004];
int fnd(int r)
{
  if(par[r]==r) return r;
  else return par[r]=fnd(par[r]);
}
int krskl(int n ,int m)
{
    int p,q,cst=0,i,cnt=0;
    for(i=0;i<n;i++) par[i]=i;
    for(i=0;i<m;i++)
    {
        p = fnd(in[i].u);
        q = fnd(in[i].v);
        if(p!=q)
        {
            cnt++;
            par[p]=q;
            cst+=in[i].w;
            if(cnt==n-1) break;
        }
    }
    return cst;
}
int main()
{
    int n,m,i,j,sm,cst,a;
    while(cin>>n>>m)
    {
        sm=0;
        if(n==0&&m==0) break;
        for(i=0;i<m;i++)
        {
            cin>>in[i].u>>in[i].v>>in[i].w;
            sm+=in[i].w;
        }
        sort(in,in+m,cmp);
        a = krskl(n,m);
        //cout<<sm<<" "<<a<<endl;
        cout<<sm-a<<endl;
    }
    return 0;
}
