#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
int n,sc;
int bfs()
{
    int vis[100]={0},cnt=0,vv,i;
    queue<int>qq;
    qq.push(sc);
    vis[sc]=1;
    while(!qq.empty())
    {
        int k = qq.front();
        qq.pop();
        for(i=0;i<v[k].size();i++)
        {
            vv = v[k][i];
            if(!vis[vv])
            {
                vis[vv]=1;
                cnt++;
                qq.push(vv);
            }
        }
    }
    return cnt;
}
int main()
{
    int m,i,j,p,q,T,a,b;
    cin>>T;
    while(T--)
    {
        cin>>sc>>n>>m;
        for(i=0;i<100;i++) v[i].clear();
        p=0;
        while(m--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        p = bfs();
        cout<<2*p<<endl;
    }
}
