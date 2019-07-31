#include<bits/stdc++.h>
using namespace std;
vector<int>v[10002];
int vis[10002],ans;
void dfs(int x)
{
    //cout<<x<<endl;
    vis[x]=1;
    for(int i=0; i<v[x].size(); i++)
    {

        if(vis[v[x][i]]==0) dfs(v[x][i]);
        else if(vis[v[x][i]]==1)
        {
            ans=1;
            return;
        }
    }
    vis[x]=2;
}
int main()
{
    //freopen("1610in.txt","r",stdin);
    //freopen("1610out.txt","w",stdout);
    int n,m,i,j,p,q,T;
    cin>>T;
    while(T--)
    {
        ans=0;
        for(i=0; i<10001; i++) v[i].clear();
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        while(m--)
        {
            cin>>p>>q;
            v[p].push_back(q);
        }
        for(i=1; i<=n; i++)
        {
            if(!vis[i]) dfs(i);
            if(ans) break;
        }
        if(ans) cout<<"SIM"<<endl;
        else cout<<"NAO"<<endl;
    }
}
