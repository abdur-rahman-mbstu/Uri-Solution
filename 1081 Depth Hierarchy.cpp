#include<bits/stdc++.h>
using namespace std;
vector<int>v[32];
bool vis[30];
void dfs(int x, int cnt)
{
    int i,k;
    vis[x]=1;
    for(i=0; i<v[x].size(); i++)
    {
        k = v[x][i];
        if(!vis[k])
        {
            for(int j=1; j<=cnt; j++) cout<<" ";
            cout<<x<<"-"<<k<<" pathR(G,"<<k<<")"<<endl;
            dfs(k,cnt+2);
        }
        else
        {
            for(int j=1; j<=cnt; j++) cout<<" ";
            cout<<x<<"-"<<k<<endl;
        }
    }
}
int main()
{
    //freopen("1081in.txt","r",stdin);
    //freopen("1081out.txt","w",stdout);
    int m,i,j,p,q,T,b[1003],n,idx,mx,t=1;
    map<int, map<int,int> >mp;
    cin>>T;
    while(T--)
    {
        mp.clear();
        memset(vis,0,sizeof(vis));
        for(i=0; i<30; i++) v[i].clear();
        cin>>n>>m;
        while(m--)
        {
            cin>>p>>q;
            if(mp[p][q]==0)
            {
                v[p].push_back(q);
                mp[p][q]=1;
            }
        }
        for(i=0; i<n; i++) sort(v[i].begin(),v[i].end());
        cout<<"Caso "<<t++<<":"<<endl;
        for(i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i,2);
                if(v[i].size()>0) cout<<endl;
            }
        }
        //cout<<endl;
    }
}
