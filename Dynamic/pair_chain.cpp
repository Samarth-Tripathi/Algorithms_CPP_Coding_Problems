#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool ss(vector<int > v1,vector<int > v2)
{
    //cout<<v1[0]<<" "<<v2[0]<<endl;
    if(v1[0]<v2[0])
        return 1;
    return 0;
}

int get(vector<vector<int > > vv)
{
    int a,b,c,m;
    vector<int > v1,v;
    v1.push_back(1);
    for(a=1;a<vv.size();a++)
    {
        m=1;
        for(b=0;b<a;b++)
        {
            if(vv[a][0]>vv[b][1])
            {
                c=v1[b]+1;
                if(m<c)
                    m=c;
            }
        }
        v1.push_back(m);
    }
    m=0;
    for(a=0;a<v1.size();a++)
    {
        if(m<v1[a])
            m=v1[a];
    }
    return m;
}

int main()
{
    int a,b,c,d;
    cin>>a;
    vector<int > v1;
    vector<vector<int > > vv;
    for(b=0;b<a;b++)
    {
        cin>>c;
        v1.push_back(c);
        cin>>c;
        v1.push_back(c);
        vv.push_back(v1);
        v1.clear();
    }
    sort(vv.begin(),vv.end(),ss);
    cout<<get(vv);

}
