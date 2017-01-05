#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void q_sort(vector<int > &v)
{
    if(v.size()==1 || !v.size())
        return;
    int a,b,c;
    vector<int > vl, vr;
    for(b=1;b<v.size();b++)
    {
        if(v[b]>v[0])
            vr.push_back(v[b]);
        else
            vl.push_back(v[b]);
    }
    q_sort(vl);
    q_sort(vr);
    c=v[0];
    for(a=0;a<vl.size();a++)
        v[a]=vl[a];
    v[a++]=c;
    for(b=0;b<vr.size();b++)
        v[a+b]=vr[b];
}

int main()
{
    int a,b,c;
    cin>>c;
    vector<int > v1;
    for(a=0;a<c;a++)
    {
        cin>>b;
        v1.push_back(b);
    }
    q_sort(v1);
    for(a=0;a<c;a++)
        cout<<v1[a]<<" ";
    cout<<endl;
}
