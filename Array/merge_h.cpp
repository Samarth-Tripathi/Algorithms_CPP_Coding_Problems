#include<iostream>
#include<stdio.h>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main()
{
    int a,b,c;
    vector<int > v1,v2,v3;
    cin>>b;
    for(a=0;a<b;a++)
    {
        cin>>c;
        v1.push_back(c);
    }
    cin>>b;
    for(a=0;a<b;a++)
    {
        cin>>c;
        v2.push_back(c);
    }
    cin>>b;
    for(a=0;a<b;a++)
    {
        cin>>c;
        v2.push_back(c);
    }
    v1.push_back(INT_MAX);
    v2.push_back(INT_MAX);
    v3.push_back(INT_MAX);
    vector<int > vheap,vf;
    int x,y,z;
    x=0;y=0;z=0;
    vheap.push_back(v1[x]);
    vheap.push_back(v2[y]);
    vheap.push_back(v3[z]);
    make_heap(vheap.begin(),vheap.end());
    int v;
    while(x<v1.size() || y<v2.size() || z<v3.size())
    {
        pop_heap(vheap.begin(),vheap.end());
        v=vheap.back();
        vheap.pop_back();
        vf.push_back(v);
        if(v==v1[x] && x<v1.size())
        {
            x++;
            vheap.push_back(v1[x]);
        }
        else if(v==v2[y] && y<v2.size())
        {
            y++;
            vheap.push_back(v2[y]);
        }
        else if(v==v3[z] && z<v3.size())
        {
            z++;
            vheap.push_back(v3[z]);
        }
        push_heap(vheap.begin(),vheap.end());
        for(a=0;a<vheap.size();a++)
            cout<<vheap[a]<<" ";
        cout<<endl;
    }
    for(a=0;a<vf.size();a++)
        cout<<vf[a]<<" ";
    cout<<endl;
}
