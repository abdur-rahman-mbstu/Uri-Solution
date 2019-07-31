#include<bits/stdc++.h>
using namespace std;
int par[30];
int find_pa(int m)
{
    if(par[m]==m) return m;
    else return par[m]=find_pa(par[m]);
}
int main()
{
    string s,s1,s2;
    map<string,int>mp;
    int p,q,i,T,cnt,ind,n,m,x,y;
    while(cin>>n>>m)
    {
        mp.clear();
        ind=1;
        cnt=n;
        for(i=0;i<=n;i++) par[i]=i;
        for(i=0;i<m;i++)
        {
            cin>>s>>s1>>s2;
            if(mp[s]==0) mp[s]=ind++;
            if(mp[s2]==0) mp[s2]=ind++;
            p = mp[s];
            q = mp[s2];
            x = find_pa(p);
            y = find_pa(q);
            if(x!=y)
            {
                cnt--;
                par[x]=y;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

