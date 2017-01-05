#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

bool get(vector<char > vv,vector<char > v1,vector<char > v2,int a,int b,int c)
{
    if(a==v1.size() && b==v2.size() && c==vv.size())
        return 1;
    /*if(a==v1.size() || b==v2.size() || c==vv.size())
        return 0;*/
    bool p,q;
    p=0;q=0;
    if(v1[a]==vv[c])
        p=1;
    if(v2[b]==vv[c])
        q=1;
    return ((p && get(vv,v1,v2,a+1,b,c+1)) || (q && get(vv,v1,v2,a,b+1,c+1)));
}

int main()
{
    int a,b,c;
    string s1,s2,ss;
    vector<char > v1,v2,vv;
    cin>>s1;
    cin>>s2;
    cin>>ss;
    if(ss.length()!= s1.length()+s2.length())
        return 0;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    for(a=0;a<s2.length();a++)
        v2.push_back(s2[a]);
    for(a=0;a<ss.length();a++)
        vv.push_back(ss[a]);
    cout<<get(vv,v1,v2,0,0,0);
}
