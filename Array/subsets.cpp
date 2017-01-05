#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void get(vector<int > v1,vector<int > &v2,int a)
{
    if(a==v1.size())
    {
        for(int b=0;b<v2.size();b++)
            cout<<v2[b]<<" ";
        cout<<endl;
        return;
    }
    get(v1,v2,a+1);
    v2.push_back(v1[a]);
    get(v1,v2,a+1);
    v2.pop_back();
}

int main()
{
    int a,b,c;
    cin>>a;
    vector<int > v1;
    for(b=0;b<a;b++)
    {
        cin>>c;
        v1.push_back(c);
    }
    vector<int > v2;
    get(v1,v2,0);

}
