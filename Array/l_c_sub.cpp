#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int get(vector<int > v)
{
    int gm,mn,a,b;
    mn=0;gm=0;
    for(a=0;a<v.size();a++)
    {
        mn+=v[a];
        if(mn<0)
            mn=0;
        if(gm<mn)
            gm=mn;
    }
    return gm;
}

int main()
{
    int a,b,c;
    vector<int > v;
    cin>>c;
    for(a=0;a<c;a++)
    {
        cin>>b;
        v.push_back(b);
    }
    cout<<get(v)<<endl;
}
