#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int get(vector<char> v1,vector<char> v2,int a, int b, vector<vector<int > > &vv)
{
    /*//cout<<a<<" "<<b<<endl;
    if(a<0 || b<0)
        return 0;
    if(vv[a][b]!=0)
        return vv[a][b];
    if(v1[a]==v2[b])
    {
        vv[a][b]= 1+ get(v1,v2,a-1,b-1,vv);
        return 1+ get(v1,v2,a-1,b-1,vv);
    }
    int p,q;
    p=get(v1,v2,a,b-1,vv);
    q=get(v1,v2,a-1,b,vv);
    if(p>q)
    {
        vv[a][b]=p;
        return p;
    }
    vv[a][b]=q;
    return q;*/
    int x,y,z,m;
    for(x=1;x<=a;x++)
    {
        for(y=1;y<=b;y++)
        {
            if(v1[x-1]==v2[y-1])
                vv[x][y]=1+vv[x-1][y-1];
            else
                vv[x][y]=max(vv[x][y-1],vv[x-1][y]);
            cout<<vv[x][y]<<" ";
        }
        cout<<endl;
    }
    return vv[--x][--y];



}

int main()
{
    int a,b,c;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<char > v1,v2;
    cout<<endl;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    for(a=0;a<s2.length();a++)
        v2.push_back(s2[a]);
    vector<vector<int > > vv;
    vector<int > v;
    for(a=0;a<=s2.length();a++)
        v.push_back(0);
    for(a=0;a<=s1.length();a++)
        vv.push_back(v);
    cout<<endl;
    cout<<get(v1,v2,v1.size(),v2.size(),vv)<<endl;
}
