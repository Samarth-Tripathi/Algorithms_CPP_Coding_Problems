#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>

using namespace std;

int get(vector<char > v1, vector<int > &vv)
{
    int a=0;
    int max=0;
    int p,q;
    for(int b=0;b<v1.size();b++)
    {
        p=v1[b];
        //cout<<p<<" ";
        if(vv[p]!=1)
        {
            vv[p]++;
            continue;
        }
        if(max<b-a)
            max=b-a;
        vv[p]++;
        q=v1[a];
        while(vv[q]!=2)
        {
            vv[q]=0;
            a++;
            q=v1[a];
        }
        vv[q]--;
        ++a;
    }
    return max;
}

int main()
{
    string s1;
    int a,b,c;
    vector<char > v1;
    cin>>s1;
    for(a=0;a<s1.length();a++)
        v1.push_back(s1[a]);
    /*int arr1[256];
    memset(arr,0,256*sizeof(int));*/
    vector<int > v(256,0);
    cout<<get(v1,v)<<endl;


}
