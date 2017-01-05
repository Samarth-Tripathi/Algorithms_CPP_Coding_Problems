#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void get (int arr[][5])
{
    //arr[0][0]=50;
    int l,r,a,b,c;
    l=0;r=4;
    while(r>l)
        {
            for(a=l;a<r;a++)
            {
                b=arr[l][a];
                arr[l][a]=arr[a][r];
                arr[a][r]=arr[r][r-a+l];
                arr[r][r-a+l]=arr[r-a+l][l];
                arr[r-a+l][l]=b;
            }
            r--;l++;
        }
    for(a=0;a<5;a++)
    {
        for(b=0;b<5;b++)
            cout<<arr[a][b]<<" ";
        cout<<endl;
    }
}

int main()
{
    int a,b,c;
    int arr[5][5]={
    11,12,13,14,15,
    16,17,18,19,20,
    21,22,23,24,25,
    26,27,28,29,30,
    31,32,33,34,35};
    for(a=0;a<5;a++)
    {
        for(b=0;b<5;b++)
            cout<<arr[a][b]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(a=0;a<5;a++)
    {
        for(b=0;b<a;b++)
            {
                c=arr[a][b];
                arr[a][b]=arr[b][a];
                arr[b][a]=c;
            }
    }
    cout<<endl;
    for(a=0;a<5;a++)
    {
        for(b=0;b<5;b++)
            cout<<arr[a][b]<<" ";
        cout<<endl;
    }
    //get(arr);

}
