#include<iostream>
#include<stdio.h>
#include<vector>
#include<climits>

using namespace std;

int p_part(vector<char > v)
{
    int a,l,k,i,j;
    int n=v.size();
    vector<vector<bool > > p;
    vector<vector<int > > vv;
    vector<bool > pp(n,0);
    vector<int > v1(n,0);
    for(a=0;a<n;a++)
    {
        p.push_back(pp);
        vv.push_back(v1);
    }
    for(l=2;l<=n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {
            j=i+l-1;
            if(l==2)
                p[i][j]=(v[i]==v[j]);
            else
                p[i][j]=(v[i]==v[j])&&(p[i+1][j-1]);
            if(p[i][j])
                vv[i][j]=0;
            else
            {
                vv[i][j] = INT_MAX;
                for (k=i;k<=j-1;k++)
                    vv[i][j]=min(vv[i][j],vv[i][k]+vv[k+1][j]+1);
            }

        }
    }
    return vv[i-1][j-1];
}

int main()
{
    int a,b,c;
    string s1;
    cin>>s1;
    vector<char > v;
    for(a=0;a<s1.length();a++)
        v.push_back(s1[a]);
    cout<<p_part(v)<<endl;
}
