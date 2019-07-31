#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[300002];
ll fun(ll x)
{
    if(x==0) return 0;
    else if(x>0) return 1;
    else return -1;
}
void update(ll node, ll st, ll ed, ll i, ll j)
{
    if(st>i||ed<i) return;
    if(st==ed)
    {
        tree[node] = fun(j);
        return;
    }
    ll rgt,lft,md;
    md = (st+ed)/2;
    lft = node*2;
    rgt = node*2+1;
    update(lft,st,md,i,j);
    update(rgt,md+1,ed,i,j);
    tree[node] = tree[lft]*tree[rgt];
}
ll quary(ll node, ll st, ll ed, ll i, ll j)
{
    ll pp=1,qq=1;
    if(st>j||ed<i) return pp*qq;
    if(st>=i&&ed<=j) return tree[node];
    ll rgt,lft,md;
    md = (st+ed)/2;
    lft = node*2;
    rgt = node*2+1;
    pp = quary(lft,st,md,i,j);
    qq = quary(rgt,md+1,ed,i,j);
    return pp*qq;
}
int main()
{
    //freopen("1084in.txt","r",stdin);
    //freopen("1084out.txt","w",stdout);
    ll n,m,z,p,q,x,y;
    char ch;
    while(cin>>n>>m)
    {
        for(z=1;z<=300000;z++) tree[z]=1;
        for(z=1; z<=n; z++)
        {
            cin>>q;
            update(1,1,n,z,q);
        }
        while(m--)
        {
            cin>>ch>>x>>y;
            if(ch=='C') update(1,1,n,x,y);
            else
            {
                p = quary(1,1,n,x,y);
                if(p==0) cout<<"0";
                else if(p<0) cout<<"-";
                else cout<<"+";
            }
        }
        cout<<endl;
    }
}

