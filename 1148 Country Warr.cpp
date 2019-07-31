#include<bits/stdc++.h>
using namespace std;
#define mx 9999999
struct node
{
    int u,w;
    node(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator<(const node&p) const
    {
        return p.w<w;
    }
};
priority_queue<node>q;
vector<int>g[502];
int d[502],cst[502][502];
bool a[502][502];
void dkt(int n, int sc)
{
    int v,u,i,p;
    for(i=0; i<=500; i++) d[i]=mx;
    q.push(node(sc,0));
    d[sc]=0;
    while(!q.empty())
    {
        node tp=q.top();
        q.pop();
        u = tp.u;
        for(i=0; i<g[u].size(); i++)
        {
            v=g[u][i];
            if(a[u][v]==1&&a[v][u]==1) p=0;
            else p = cst[u][v];
            if(d[u]+p<d[v])
            {
                d[v]=d[u]+p;
                q.push(node(v,d[v]));
            }
        }
    }
}
int main()
{
    int i,n,m,edge,nd,wt,qry;
    while(cin>>nd>>edge)
    {
        if(nd==0&&edge==0) break;
        memset(a,0,sizeof(a));
        for(i=1; i<=500; i++) g[i].clear();
        while(edge--)
        {
            cin>>n>>m>>wt;
            g[n].push_back(m);
            cst[n][m]=wt;
            a[n][m]=1;
        }
        cin>>qry;
        while(qry--)
        {
            cin>>n>>m;
            dkt(nd,n);
            //for(i=1; i<=nd; i++) cout<<n<<" "<<i<<" "<<d[i]<<endl;
            if(d[m]==mx) cout<<"Nao e possivel entregar a carta"<<endl;
            else cout<<d[m]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

