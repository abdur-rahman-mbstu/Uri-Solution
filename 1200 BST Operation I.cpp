#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *lft,*rht;
}*root;
void inorder(struct node *r);
void preorder(struct node *r);
void postorder(struct node *r);
struct node* insrt(struct node *r, int data);
vector<int>v;
int main()
{
    int n,p,q,i,t=1,T,ind=1,d;
    root=NULL;
    string s,s1,s2;
    char c;
    map<char,int>mp;
    while(getline(cin,s))
    {
        n = s.size();
        p=0;
        s1.clear();
        s2.clear();
        for(i=0; i<n; i++)
        {
            if(isalpha(s[i]))
            {
                if(p==0) s1.push_back(s[i]);
                else s2.push_back(s[i]);
            }
            if(s[i]==' ') p=1;
        }
        //cout<<s1<<" "<<s2<<endl;
        if(s1=="INFIXA")
        {
            v.clear();
            inorder(root);
            for(i=0;i<v.size();i++)
            {
                if(i==0) printf("%c",v[i]);
                else printf(" %c",v[i]);
            }
            cout<<endl;
        }
        else if(s1=="PREFIXA")
        {
            v.clear();
            preorder(root);
            for(i=0;i<v.size();i++)
            {
                if(i==0) printf("%c",v[i]);
                else printf(" %c",v[i]);
            }
            cout<<endl;
        }
        else if(s1=="POSFIXA")
        {
            v.clear();
            postorder(root);
            for(i=0;i<v.size();i++)
            {
                if(i==0) printf("%c",v[i]);
                else printf(" %c",v[i]);
            }
            cout<<endl;
        }
        else if(s1=="I")
        {
            c = s2[0];
            if(mp[c]==0) mp[c] = ind++;
            d = c;
            root = insrt(root,d);
        }
        else if(s1=="P")
        {
            c = s2[0];
            if(mp[c]) cout<<c<<" existe"<<endl;
            else  cout<<c<<" nao existe"<<endl;
        }
    }
}
struct node* insrt(struct node *r,int data)
{
    if(r==NULL)
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->val=data;
        r->lft=NULL;
        r->rht=NULL;
    }
    else if(data<r->val) r->lft=insrt(r->lft,data);
    else r->rht=insrt(r->rht,data);
    return r;
};
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->lft);
        v.push_back(r->val);
        inorder(r->rht);
    }
}
void preorder(struct node *r)
{
    if(r!=NULL)
    {
        v.push_back(r->val);
        preorder(r->lft);
        preorder(r->rht);
    }
}
void postorder(struct node *r)
{
    if(r!=NULL)
    {
        postorder(r->lft);
        postorder(r->rht);
        v.push_back(r->val);
    }
}

