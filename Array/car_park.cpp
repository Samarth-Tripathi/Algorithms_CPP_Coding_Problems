#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int m_set(vector<int > &v,int a)
{
    //cout<<a<<"bb ";
    //vector<int > s1;
    int c=0;
    int x,y;
    x=v[a];
    while(x!=-1)
    {
        //cout<<x<<" "<<a<<" ";
        //s1.push_back(x);
        ++c;
        v[a]=-1;
        a=x;
        x=v[x];
    }
    //x=s1.size();
    //s1.clear();
    return c+1;
}

int get(vector<int > &v)
{
    int a,b,c;c=0;
    for(a=0;a<v.size();a++)
    {
        if(v[a]==-1 || v[a]==a)
            continue;
        c+=m_set(v,a);
    }
    return c;
}

int main()
{
    int a,b,c;
    vector<int > v;
    cin>>a;
    for(b=0;b<a;b++)
    {
        cin>>c;
        v.push_back(c);
    }
    cout<<endl<<get(v);
}
