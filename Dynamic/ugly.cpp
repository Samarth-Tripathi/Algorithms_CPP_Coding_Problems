#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int g_ugly(vector<int > v1, int &a, int &b, int &c)
{
    if(2*v1[a]<=3*v1[b] && 2*v1[a]<=5*v1[c])
    {
        ++a;
        return 2*v1[a-1];
    }
    if(2*v1[a]>=3*v1[b] && 3*v1[b]<=5*v1[c])
    {
        ++b;
        return 3*v1[b-1];
    }
    ++c;
    return 5*v1[c-1];
}

int main()
{
    int a,b,c,m;
    vector<int > v1;
    a=0;b=0;c=0;
    v1.push_back(1);
    for(int i=0;i<30;i++)
    {
        m=g_ugly(v1,a,b,c);
        if(m!=v1.back())
            v1.push_back(m);
    }
    for(int j=0;j<v1.size();j++)
        cout<<v1[j]<<" ";
}
