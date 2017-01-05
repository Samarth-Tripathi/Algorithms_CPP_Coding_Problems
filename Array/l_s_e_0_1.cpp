#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int get(vector<bool > v)
{
    vector<int > vv,v1;
    int a,b,c;
    bool p;
    b=0;
    for(a=0;a<v.size();a++)
    {
        if(v[a]==0)
            v1.push_back(-1);
        else
            v1.push_back(1);
        b+=v1[a];
        vv.push_back(b);
    }

}

int main()
{
    int a,c;
    vector<bool > v;
    cin>>c;
    bool b
    for(a=0;a<c;a++)
    {
        cin>>b;
        v.push_back(b);
    }
    cout<<get(v)<<endl;
}
