#include<bits/stdc++.h>
using namespace std;
vector<int>g[2005];
bool vis[2005];
queue<int>q;
void bfs(int sc)
{
    q.push(sc);
    vis[sc]=1;
    int v,u,i;
    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v = g[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int rd,cn,i,j,p,fm,to,k;
    while(cin>>rd>>cn)
    {
        k=0;
        for(i=1;i<=2000;i++) g[i].clear();
        if(rd==0&&cn==0) break;
        while(cn--)
        {
            cin>>fm>>to>>p;
            if(p==1) g[fm].push_back(to);
            else
            {
               g[fm].push_back(to);
               g[to].push_back(fm);
            }
        }
        for(i=1;i<=rd;i++)
        {
            memset(vis,0,sizeof(vis));
            bfs(i);
            for(j=1;j<=rd;j++)
            {
                if(vis[j]==0)
                {
                    cout<<0<<endl;
                    k=1;
                    break;
                }
            }
            if(k==1) break;
        }
        if(k==0) cout<<1<<endl;
    }
    return 0;
}
