#include<bits/stdc++.h>
using namespace std;


vector<int>v[1002];
bool vis[1002];

void dfs(int sc)
{
    int i,pp;
    vis[sc]=1;
    for(i=0; i<v[sc].size(); i++)
    {
        pp = v[sc][i];
        if(!vis[pp]) dfs(pp);
    }
}

int main()
{
    int i,j,n,m,p,q,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        while(m--)
        {
            cin>>p>>q;
            v[p].push_back(q);
        }
        int f=0;
        for(i=1; i<=n; i++)
        {
            int k=0;
            memset(vis,0,sizeof(vis));
            dfs(i);
            for(j=1; j<=n; j++)
            {
                if(!vis[j])
                {
                    k=1;
                    break;
                }
            }
            if(!k)
            {
                f=1;
                break;
            }
        }
        if(f) cout<<"S"<<endl;
        else cout<<"N"<<endl;
        for(i=1; i<=n; i++) v[i].clear();
    }
}
