#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int get(vector<char > v1, vector<char > v2,int x,int y)
{
    /*cout<<a<<" "<<b<<endl;
    if(a<0 && b<0)
        return 0;
    if(a<0)
        return b;
    if(b<0)
        return a;
    if(v1[a]==v2[b])
        return get(v1,v2,a-1,b-1);
    if(1)
    {
        int x,y,z;
        x=get(v1,v2,a-1,b-1)+1;
        y=get(v1,v2,a-1,b)+1;
        z=get(v1,v2,a,b-1)+1;
        if(x<=y && x<=z)
            return x;
        if(y<=z)
            return y;
        return z;
    }*/
    int a,b,c,d,m;
    vector<int > v;
    vector<vector<int > > vv;
    for(a=0;a<=x;a++)
    {
        for(b=0;b<=y;b++)
            v.push_back(0);
        vv.push_back(v);
        v.clear();
    }
    for(a=1;a<=x;a++)
        vv[a][0]=a;
    for(b=1;b<=y;b++)
        vv[0][b]=b;
    for(a=1;a<=x;a++)
    {
        for(b=1;b<=y;b++)
        {
            if(v1[a-1]==v2[b-1])
                vv[a][b]=vv[a-1][b-1];
            else
            {
                vv[a][b]=min(vv[a-1][b-1],min(vv[a-1][b],vv[a][b-1]))+1;
            }
            cout<<vv[a][b]<<" ";
        }
        cout<<endl;
    }
    return vv[--a][--b];
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<char > v1,v2;
    for(int a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    for(int b=0;b<s2.length();b++)
        v2.push_back(s2[b]);
    cout<<endl<<get(v1,v2,v1.size(),v2.size())<<endl;

}
