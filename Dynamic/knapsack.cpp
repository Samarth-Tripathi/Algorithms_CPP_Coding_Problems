#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int r_get(vector<int > n,vector<int > w,int m,int s)
{
    if(s==0 || m==0)
        return 0;
    if(w[s]>m)
        return r_get(n,w,m,s-1);
    return max(n[s]+r_get(n,w,m-w[s],s-1) , r_get(n,w,m,s-1));
}

int d_get(vector<int > n,vector<int > w, int m)
{
    vector<vector<int > > vv;
    vector<int > v1;
    int a,b,c;
    for(a=0;a<=n.size();a++)
    {
        for(b=0;b<=m;b++)
            v1.push_back(0);
        vv.push_back(v1);
        v1.clear();
    }
    for(a=1;a<=n.size();a++)
    {
        for(b=0;b<=m;b++)
        {
            if(w[a-1]<=b)
                vv[a][b]= max(vv[a-1][b], n[a-1] + vv[a-1][b-w[a-1]]);
            else
                vv[a][b]=vv[a-1][b];
            cout<<vv[a][b]<<" ";
        }
        cout<<endl;
    }
    return vv[a-1][b-1];
}

int main()
{
    int a,b,c,m;
    vector<int > n,w;
    cin>>m;
    cin>>a;
    for(b=0;b<a;b++)
    {
        cin>>c;
        n.push_back(c);
        cin>>c;
        w.push_back(c);
    }
    cout<<r_get(n,w,m,n.size()-1)<<endl;
    cout<<endl<<d_get(n,w,m);
}
