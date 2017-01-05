#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void get(vector<int > v1,int n)
{
    int a,b,c,m;
    vector<vector<int > > vv;
    vector<int > v;
    for(a=0;a<=v1.size();a++)
    {
        for(b=0;b<=n;b++)
            v.push_back(0);
        vv.push_back(v);
        v.clear();
    }
    for(a=1;a<=v1.size();a++)
        vv[a][0]=1;
    for(a=1;a<=v1.size();a++)
    {
        for(b=1;b<=n;b++)
        {
            if(v1[a-1]<=b)
            {
                vv[a][b]=vv[a-1][b]+vv[a][b-v1[a-1]];
            }
            else
                vv[a][b]=vv[a-1][b];
            cout<<vv[a][b]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a,b,c,n;
    cin>>n;
    cin>>a;
    vector<int > v1;
    for(b=0;b<a;b++)
    {
        cin>>c;
        v1.push_back(c);
    }
    get(v1,n);
}
