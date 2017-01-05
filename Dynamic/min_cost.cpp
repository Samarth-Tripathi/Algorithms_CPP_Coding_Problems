#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int m_min(int a,int b,int c)
{
    if(a<=b && a<=c)
        return a;
    if(b<=c)
        return b;
    return c;
}

int get(vector<vector<int > > vv1, vector<vector<int > > vv2)
{
    int a,b,i,j;
    i=vv1.size()-1;
    j=vv1[0].size()-1;
    vv2[0][0]=vv1[0][0];
    for(a=1;a<=j;a++)
    {
        vv2[0][a]=vv2[0][a-1]+vv1[0][a];
    }
    for(a=1;a<=i;a++)
    {
        vv2[a][0]=vv2[a-1][0]+vv1[a][0];
    }
    for(a=1;a<=i;a++)
    {
        for(b=1;b<=j;b++)
            vv2[a][b]=m_min(vv2[a-1][b-1],vv2[a-1][b],vv2[a][b-1])+vv1[a][b];
    }
    return vv2[--a][--b];

}

int main()
{
    int a,b,c,d,e;
    cin>>a;
    cin>>b;
    vector<int > v,v2;
    vector<vector<int > > vv,vv2;
    for(c=0;c<a;c++)
    {
        for(d=0;d<b;d++)
        {
            cin>>e;
            v.push_back(e);
            v2.push_back(0);
        }
        vv.push_back(v);
        vv2.push_back(v2);
        v.clear();
        v2.clear();
    }
    cout<<get(vv,vv2);
}
