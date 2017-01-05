#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

int get(vector<char > v1)
{
    map<char,int> m1;
    map<char,int> :: iterator p;
    m1[v1[0]]=0;
    int b=0;
    int f=1;
    int c=1;
    int m=0;
    while(f<v1.size())
    {
        p=m1.find(v1[f]);
        if(p==m1.end() || m1[v1[f]]+c < f)
        {
            m1[v1[f]]=f;
            ++c;
            if(m<c)
                m=c;
        }
        else
        {
            c=f-m1[v1[f]];
            m1[v1[f]]=f;
            if(m<c)
                m=c;
        }
        //cout<<c<<" "<<m<<" "<<f<<endl;
        ++f;
    }
    return m;
}

int main()
{
    string s1;
    cin>>s1;
    vector<char > v1;
    for(int a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    cout<<get(v1);
}
