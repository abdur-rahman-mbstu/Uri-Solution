#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k,p,q,v[402][402],a,b;
    while(cin>>n>>m>>q)
    {
        memset(v,0,sizeof(v));
        while(m--)
        {
            cin>>a>>b;
            v[a][b]=1;
            v[b][a]=1;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                v[i][i]=1;
                for(j=1;j<=n;j++)
                {
                    v[i][j] = (v[i][j]||(v[i][k]&&v[k][j]));
                }
            }
        }
        while(q--)
        {
            cin>>a>>b;
            if(v[a][b]) cout<<"Lets que lets"<<endl;
            else cout<<"Deu ruim"<<endl;
        }
    }
}
