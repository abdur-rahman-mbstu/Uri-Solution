#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int vis[20][20],dis[20][20];
//pair<int,int>pp;
queue<pair<int,int> >qq;
int fx[]= {2,2,-2,-2,1,-1,1,-1},
    fy[]= {1,-1,1,-1,2,2,-2,-2},scx,scy,tax,tay;
void bfs(int sx,int sy)
{
    while(!qq.empty()) qq.pop();
    int tx,ty;
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    qq.push(pii(sx,sy));
    while(!qq.empty())
    {
        pii tp = qq.front();
        qq.pop();
        for(int i=0; i<8; i++)
        {
            tx = tp.first+fx[i];
            ty = tp.second+fy[i];
            if(tx>=1&&tx<=8&&ty>=1&&ty<=8&&vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                qq.push(pii(tx,ty));
                dis[tx][ty]=dis[tp.first][tp.second]+1;
                if(tx==tax&&ty==tay) break;
            }
        }
    }
}
int main()
{
    int n,i,j,ind=1;
    string rx,ry;
    while(cin>>rx>>ry)
    {
        memset(vis,0,sizeof(vis));
        scx = rx[0]-96;
        scy = rx[1]-'0';
        tax = ry[0]-96;
        tay = ry[1]-'0';
        bfs(scx,scy);
        cout<<"To get from "<<rx<<" to "<<ry<<" takes "<<dis[tax][tay]<<" knight moves."<<endl;
    }
    return 0;
}
