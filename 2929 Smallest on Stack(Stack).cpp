#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,j,p,q,mn;
    stack<int>st;
    string s;
    while(cin>>n)
    {
        mn=1e9+5;
        while(!st.empty()) st.pop();
        while(n--)
        {
            cin>>s;
            if(s=="PUSH")
            {
                cin>>m;
                if(st.empty())
                {
                    st.push(m);
                    mn = m;
                    continue;
                }
                if(m>=mn) st.push(m);
                else
                {
                    st.push(2*m-mn);
                    mn = m;
                }
            }
            else if(s=="POP")
            {
                if(st.size()==0)
                {
                    cout<<"EMPTY"<<endl;
                    continue;
                }
                p = st.top();
                st.pop();
                if(p<mn) mn = 2*mn-p;
            }
            else if(s=="MIN")
            {
                if(st.size()==0)
                {
                    cout<<"EMPTY"<<endl;
                    continue;
                }
                cout<<mn<<endl;
            }
        }
    }
}
