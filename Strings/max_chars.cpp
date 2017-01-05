#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<cstring>

using namespace std;

int get(vector<char > v)
{
    map<char, int> m1;
    map<char, int> :: iterator i1;
    for(int a=0;a<v.size();a++)
    {
        i1= m1.find(v[a]);
        if(i1==m1.end())
            m1[v[a]]=1;
        else
            m1[v[a]]+=1;
    }
    int s=0;
    for(i1=m1.begin();i1!=m1.end();i1++)
    {
        if(i1->second > s)
            s=i1->second;
    }
    return s;
}

int get2(vector<char > v)
{
    int arr[26];
    int p;
    memset(arr, 0, 26*sizeof(int));
    for(int a=0;a<v.size();a++)
    {
        p=v[a];
        if(p<97)
            p+=32;
        p-=97;
        ++arr[p];
    }
    int s=0;
    for(int b=0;b<26;b++)
    {
        //cout<<arr[b];
        if(s<arr[b])
            s=arr[b];
    }
    return s;
}

int main()
{
    int a,b,c;
    char ch;
    string s1;
    cin>>s1;
    vector<char > v1;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    cout<<get(v1)<<endl;
    cout<<get2(v1)<<endl;
}
