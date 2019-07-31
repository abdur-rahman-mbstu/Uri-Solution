#include<bits/stdc++.h>
using namespace std;
int n,c,l,p;
vector<int>v[60];
queue<int>q;
void bfs()
{
    int i,j,u,k,vis[60]={0},dis[60];
    for(i=1;i<55;i++) dis[i]=123456;
    q.push(l);
    vis[l]=1;
    dis[l]=0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i=0;i<v[u].size();i++)
        {
            k = v[u][i];
            if(!vis[k])
            {
                vis[k]=1;
                dis[k]=dis[u]+1;
                q.push(k);
            }
        }
    }
    int kk=0;
    for(i=1;i<=c;i++)
    {
        if(dis[i]<=p&&i!=l)
        {
            //if(kk==0)
            cout<<i<<" ";
            //else cout<<" "<<i;
            kk=1;
        }
    }
}
int main()
{
    int a,b,t=1,i,q=0;
    while(cin>>c>>n>>l>>p)
    {
        if(c==0&&n==0&&l==0&&p==0) break;
        for(i=0;i<55;i++) v[i].clear();
        while(n--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cout<<"Teste "<<t++<<endl;
        bfs();
        cout<<endl<<endl;
    }
    return 0;
}

