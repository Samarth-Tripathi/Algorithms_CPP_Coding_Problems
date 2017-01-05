#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int parent(vector<int > v,int a,int b)
{
    if(a<b){
    if(a/2>0)
        return a/2;}
    return 0;
}

int left(vector<int > v,int a,int b)
{
    if(2*a<b)
        return 2*a;
    return 0;
}

int right(vector<int > v,int a,int b)
{
    if(2*a+1<b)
        return 2*a+1;
    return 0;
}

void heapify(vector<int > &v,int a,int b)
{
    int l=left(v,a,b);
    int r=right(v,a,b);
    if(l==0 && r==0)
        return;
    int p;
    if(v[l]>v[r] && v[l]>v[a])
    {
        p=v[l];
        v[l]=v[a];
        v[a]=p;
        heapify(v,l,b);
        return;
    }
    if(v[l]<v[r] && v[r]>v[a])
    {
        p=v[r];
        v[r]=v[a];
        v[a]=p;
        heapify(v,r,b);
        return;
    }
    return;
}

void b_heap(vector<int > &v,int b)
{
    for(int a=b/2;a>=1;a--)
        heapify(v,a,b);
}

void heapsort(vector<int > &v,int b)
{
    int p,q,r;
    r=b;
    for(int a=b;a>=2;a--)
    {
        p=v[1];
        v[1]=v[a];
        v[a]=p;
        heapify(v,1,a-1);
    }
}

int main()
{
    int a,b,c;
    vector<int > v1;
    cin>>a;
    v1.push_back(0);
    for(b=0;b<a;b++)
    {
        cin>>c;
        v1.push_back(c);
    }
    b_heap(v1,v1.size());
    heapsort(v1,a);
    for(b=1;b<=a;b++)
        cout<<v1[b]<<" ";
    cout<<endl;
}
