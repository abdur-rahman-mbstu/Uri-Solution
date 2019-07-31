#include<bits/stdc++.h>
using namespace std;
vector<int>v[205],cost[205],pr;
struct info
{
    int u,w;
    info(int a, int b)
    {
        u = a;
        w = b;
    }
    bool operator<(const info&p) const
    {
        return p.w<w;
    }
};
priority_queue<info>pq;
void djk(int tar, int n)
{
    int d[505],i,j,u,vv,dis[1000]= {0},par[505],kk;
    for(i=0; i<=201; i++) dis[i]=555555;
    pq.push(info(1,0));
    dis[1]=0;
    while(!pq.empty())
    {
        info tp = pq.top();
        pq.pop();
        u = tp.u;
        for(i=0; i<v[u].size(); i++)
        {
            vv = v[u][i];
            if(dis[u]+cost[u][i]<dis[vv])
            {
                dis[vv]=dis[u]+cost[u][i];
                par[vv] = u;
                pq.push(info(vv,dis[vv]));
            }
        }
    }
    if(dis[tar]<120) cout<<"Will not be late. Travel time - "<<dis[tar]<<" - best way -";
    else cout<<"It will be "<<dis[tar]-120<<" minutes late. Travel time - "<<dis[tar]<<" - best way -";
    pr.clear();
    kk = par[tar];
    pr.push_back(tar);
    if(kk!=1)
    {
        while(1)
        {
            pr.push_back(kk);
            kk = par[kk];
            if(kk==1) break;
        }
    }
    pr.push_back(1);
    for(i=0; i<pr.size(); i++) cout<<" "<<pr[i];
    cout<<endl;
}
int main()
{
    int T,t=1,i,j,p,q,n,m,src,cst,tar;
    string ct1,ct2,fr,to;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for(i=0; i<=201; i++)
        {
            v[i].clear();
            cost[i].clear();
        }
        while(m--)
        {
            cin>>p>>q>>cst;
            v[p].push_back(q);
            v[q].push_back(p);
            cost[p].push_back(cst);
            cost[q].push_back(cst);
        }
        cin>>tar;
        djk(tar,n);
    }
    return 0;
}
