#include<iostream>
#include<stdio.h>
#include<vector>
#include<climits>

using namespace std;
//memoization
int get(vector<int > v1,vector<vector<int > > vv,int i,int j)
{
    if(vv[i][j]<INT_MAX)
        return vv[i][j];
    if(i==j)
    {
        vv[i][j]=0;
        return 0;
    }
    int m= INT_MAX;
    int a,b;
    for(a=i;a<j;a++)
    {
        b=get(v1,vv,i,a) + get(v1,vv,a+1,j) + v1[i-1]*v1[a]*v1[j];
        cout<<i<<" "<<j<<" "<<a<<" "<<v1[i-1]<<" "<<v1[a]<<" "<<v1[j]<<" "<<get(v1,vv,i,a)<<" "<<get(v1,vv,a+1,j)<<endl;
        if(b<m)
            m=b;
    }
    cout<<endl;
    vv[i][j]=m;
    return m;

}

int main()
{
    int a,b,c,d;
    cin>>a;
    vector<int > v1,v2;
    for(b=0;b<a;b++)
    {
        cin>>c;
        v2.push_back(c);
    }

    vector<vector<int > > vv;
    for(b=0;b<a;b++)
    {
        v1.clear();
        for(c=0;c<a;c++)
            v1.push_back(INT_MAX);
        vv.push_back(v1);
    }
    cout<<get(v2,vv,1,a-1);

}
