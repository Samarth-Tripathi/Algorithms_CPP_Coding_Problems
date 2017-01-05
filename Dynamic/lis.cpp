#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void get(vector<int > v1, vector<int > &v2)
{
    int a,b,c,m;
    m=1;
    v2.push_back(1);
    for(a=1;a<v1.size();a++)
    {
        for(b=0;b<a;b++)
        {
            if(v1[a]>v1[b])
            {
                c=v2[b]+1;
                if(c>m)
                    m=c;
            }
        }
        v2.push_back(m);
        m=1;
    }
}

int main()
{
    int a,b,c;
    cin>>a;
    vector<int > v1,v2;
    for(b=0;b<a;b++)
    {
        cin>>c;
        v1.push_back(c);
    }
    get(v1,v2);
    b=0;
    for(a=0;a<v2.size();a++)
    {
        if(v2[a]>b)
            b=v2[a];
    }
    cout<<b<<endl;
}
