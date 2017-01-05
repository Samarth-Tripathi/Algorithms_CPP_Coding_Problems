#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void get(vector<char > v1, vector<char > v2, int a, int b)
{
    static vector<char > vv;
    if(a==v1.size() && b==v2.size())
    {
        for(int p=0;p<vv.size();p++)
            cout<<vv[p]<<" ";
        cout<<endl;
        return;
    }
    if(a<v1.size())
    {
        vv.push_back(v1[a]);
        get(v1,v2,a+1,b);
        vv.pop_back();
    }
    if(b<v2.size())
    {
        vv.push_back(v2[b]);
        get(v1,v2,a,b+1);
        vv.pop_back();
    }
}

int main()
{
    string s1,s2;
    int a,b,c;
    cin>>s1;
    cin>>s2;
    vector<char > v1,v2;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    for(a=0;a<s2.length();a++)
        v2.push_back(s2[a]);
    get(v1,v2,0,0);
}
