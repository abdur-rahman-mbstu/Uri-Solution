#include<bits/stdc++.h>
using namespace std;
int edge,pr[40005];
struct info
{
    int u,v,w;
} in[40005];
bool cmp(info a, info b)
{
    return a.w<b.w;
}
int fnd(int r)
{
    if(pr[r]==r) return r;
    else return pr[r]=fnd(pr[r]);
}
int mst(int n)
{
    int k,q,sm=0,cnt=0;
    for(int i=0; i<=n; i++) pr[i]=i;
    sort(in,in+edge,cmp);
    for(int i=0; i<edge; i++)
    {
        k=fnd(in[i].u);
        q=fnd(in[i].v);
        //cout<<k<<" "<<q<<endl;
        if(k!=q)
        {
            pr[k]=q;
            cnt++;
            sm+=in[i].w;
            if(cnt==n-1) break;
        }
    }
    return sm;
}
int main()
{
    int node,i,j,nod,nod1,wt;
    while(cin>>node>>edge)
    {
        if(node==0&&edge==0) break;
        for(i=0; i<edge; i++)
        {
            cin>>nod>>nod1>>wt;
            in[i].u=nod;
            in[i].v=nod1;
            in[i].w=wt;
        }
        cout<<mst(node)<<endl;
    }
    return 0;
}
