#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void swap(char &a, char &b)
{
    char c;
    //cout<<a<<" "<<b<<endl;
    c=a;a=b;b=c;
}

bool mmax(const char &a, const char &b)
{
    int p,q;
    p=a;q=b;
    if(p>q)
        return 1;
    return 0;
}

void get(vector<char > v1,int a)
{
    if (a==v1.size()-1)
    {
        for(int c=0;c<=a;c++)
            cout<<v1[c];
        cout<<endl;
        return;
    }
    int b;
    for(b=a;b<v1.size();b++)
    {
        if((b!=a && v1[b]==v1[a]) || (b>a && v1[b]==v1[b-1]))
            continue;
        swap(v1[b],v1[a]);
        get(v1,a+1);
        swap(v1[b],v1[a]);
    }
}

void get2(vector<char > v)
{
    int a;
    for(a=0;a<v.size();a++)
        cout<<v[a];
    cout<<endl;
    while( prev_permutation(v.begin(), v.end()))
    {
        for(a=0;a<v.size();a++)
            cout<<v[a];
        cout<<endl;
    }
}

int main()
{
    int a,b,c;
    string s1;
    cin>>s1;
    vector<char > v1;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    get(v1,0);
    /*sort(v1.begin(), v1.end(), mmax);
    cout<<endl;
    get2(v1);*/

}
