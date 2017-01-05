#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



int main()
{
    int a,b,c;
    vector<int > v;
    //char p;
    v.push_back(16);
    v.push_back(28);
    v.push_back(152);
    v.push_back(633);
    v.push_back(9);
    v.push_back(46);
    v.push_back(7216);
    for(a=0;a<4;a++)
    {
        stable_sort(v.begin(),v.end(),p);
    }
}
