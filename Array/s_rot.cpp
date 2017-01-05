#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
/*
int get(vector<int > v,int val,int a,int b)
{
    int x,y,z,m;
    m=(a+b)/2;
    if(v[m]==val)
        return m;
    if(a==b)
        return -1;
    if(v[m]<val)
        return get(v,val,m+1,b);
    return get(v,val,a,m-1);
}*/

int get(vector<int > v,int a,int b)
{
    if(a==b)
        return a;
    if(a==b-1)
    {
        if(v[a]<v[b])
            return a;
        return b;
    }
    int m=(a+b)/2;
    if(v[a]<v[m])
        return get(v,m,b);
    return get(v,a,m);

}

int b_s(vector<int > v,int a,int b,int c)
{
    if(a==b)
    {
        if(v[a]==c)
            return a;
        return -1;
    }
    if(a==b-1)
    {
        if(v[a]==c)
            return a;
        if(v[b]==c)
            return b;
        return -1;
    }
    int m;
    m=(a+b)/2;
    if(c>v[m])
        return b_s(v,m,b,c);
    return b_s(v,a,m,c);
}

int main()
{
    int a,b,c;
    cin>>c;
    vector<int > v;
    for(a=0;a<c;a++)
    {
        cin>>b;
        v.push_back(b);
    }
    cin>>c;
    rotate(v.begin(),v.begin()+c,v.end());
    cout<<endl;
    cin>>c;
    a=get(v,0,v.size()-1);
    if(c>=v[0] && c>=v[a])
        cout<<b_s(v,0,a,c);
    else
        cout<<b_s(v,a,b,c);
}
