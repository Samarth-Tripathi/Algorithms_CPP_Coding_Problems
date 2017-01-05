#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int get(vector<int > &v, int k)
{
    sort(v.begin(),v.end());
    int a,b,c;
    bool p;c=0;
    for(a=0;a<v.size();a++)
    {
        b=v[a]+k;
        p=binary_search(v.begin(),v.end(),b);
        if(p)
            c++;
    }
    return c;
}

int main()
{
    int a,b,c,n,k;
    vector<int > v;
    cin>>n;
    cin>>k;
    for(a=0;a<n;a++)
    {
        cin>>b;
        v.push_back(b);
    }
    cout<<get(v,k);

}
