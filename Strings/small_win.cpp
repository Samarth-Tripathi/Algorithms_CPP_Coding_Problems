#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void b_count(vector<char > v1,vector<int > &vv1)
{
    int a,b,c;
    for(a=0;a<v1.size();a++)
    {
        b=v1[a];
        ++vv1[b];
    }
}

bool check(vector<int > v1,vector<int > v2)
{
    for(int a=0;a<v1.size();a++)
    {
        if(v2[a]<v1[a])
            return 0;
    }
    return 1;
}

int get(vector<int > v1,vector<int > &v2,vector<char > v)
{
    int p,q,min,a,b;
    for(a=0;a<v.size();a++)
    {
        p=v[a];
        v2[p]++;
        if(check(v1,v2))
            break;
    }
    min=a;
    b=0;
    while(a<v.size())
    {
        ++a;
        p=v[a];
        v2[p]++;
        if(v[a]==v[b])
        {
            while(check(v1,v2))
            {
                b++;
                q=v[b];
                v2[q]--;
            }
            --b;
            v2[q]++;
            if(min>a-b)
                min=a-b;
        }

    }
    return min;
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<char > v1,v2;
    int a,b,c;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    for(a=0;a<s2.length();a++)
        v2.push_back(s2[a]);
    vector<int > vv1(256,0);
    b_count(v1,vv1);
    vector<int > vv2(256,0);
    cout<<get(vv1,vv2,v2)<<endl;

}
