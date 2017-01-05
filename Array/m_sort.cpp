#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void merge(vector<int > &v,int a,int m,int b)
{
    int x,y,z;
    static vector<int > vv;
    x=a;y=m+1;
    while(x<=m && y<=b)
    {
        if(v[x]<v[y])
        {
            vv.push_back(v[x]);
            ++x;
        }
        else
        {
            vv.push_back(v[y]);
            ++y;
        }
    }
    while(x<=m)
    {
        vv.push_back(v[x]);
        ++x;
    }
    while(y<=b)
    {
        vv.push_back(v[y]);
        ++y;
    }
    for(x=a;x<=b;x++)
        v[x]=vv[x-a];
    vv.clear();
}

void m_sort(vector<int > &v,int a,int b)
{
    if((b-a) ==0 || a>b)
        return;
    if((b-a) ==1)
    {
        if(v[a]>v[b])
        {
            int p=v[a];
            v[a]=v[b];
            v[b]=p;
        }
        return;
    }
    int x,y,m;
    m=(b+a)/2;
    m_sort(v,a,m);
    m_sort(v,m+1,b);
    merge(v,a,m,b);
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
    m_sort(v,0,v.size()-1);
    for(a=0;a<v.size();a++)
        cout<<v[a]<<" ";
    cout<<endl;
}
