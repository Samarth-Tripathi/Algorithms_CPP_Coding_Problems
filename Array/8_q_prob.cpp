#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<map>
#include<iterator>


using namespace std;

bool val(int y,map<int,bool > m)
{
    map<int,bool> :: iterator i1;
    i1=m.find(y);
    if(i1->second==1)
        return 0;
    return 1;
}

bool chd(int c,int r,map<int,int> m2)
{
    map<int,int> :: iterator i1;
    int a,b;
    for(i1=m2.begin();i1!=m2.end();i1++)
    {
        a=i1->first;
        b=i1->second;
        if(abs(a-r)==abs(b-c))
            return 0;
    }
    return 1;
}

int get(vector<vector<bool > > &vv,map<int,bool > &m,int x,map<int,int> &m2)
{
    if(x==8)
        {
            for(int p=0;p<8;p++)
            {
                for(int q=0;q<8;q++)
                    cout<<vv[p][q]<<" ";
                cout<<endl;
            }
            cout<<endl;
            cout<<endl;
            return 1;
        }
    //cout<<x<<endl;
    int a,b,c;
    c=0;
    for(a=0;a<8;a++)
    {
        if(val(a,m) && a!=x && chd(a,x,m2))
        {
            vv[x][a]=1;
            m[a]=1;
            m2[x]=a;
            c+=get(vv,m,x+1,m2);
            vv[x][a]=0;
            m[a]=0;
            m2.erase(x);
        }
    }
    return c;
}

int main()
{
    int a,b,c;c=0;
    vector<bool> p(8,0);
    vector<vector<bool > > vv;
    for(a=0;a<8;a++)
        vv.push_back(p);
    map<int,bool> mcol;
    for(a=0;a<8;a++)
        mcol[a]=0;
    map<int,int> mrc;
    for(a=0;a<8;a++)
    {
        vv[0][a]=1;
        mcol[a]=1;
        mrc[0]=a;
        c+=get(vv,mcol,1,mrc);
        vv[0][a]=0;
        mcol[a]=0;
        mrc.erase(0);
    }
    cout<<c<<endl;
}
