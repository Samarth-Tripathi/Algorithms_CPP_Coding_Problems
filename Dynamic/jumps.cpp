#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int get(vector<int > v1)
{
    vector<int > v2;
    v2.push_back(0);
    int a,b;
    for(a=1;a<v1.size();a++)
    {
        for(b=0;b<a;b++)
        {
            if(a<=v1[b]+b)
            {
                v2.push_back(v2[b]+1);
                break;
            }
        }
        //cout<<v2[a]<<" ";
    }
    return v2.back();
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
    cout<<get(v1);

}
