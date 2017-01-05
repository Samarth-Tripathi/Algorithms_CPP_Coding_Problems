#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

bool chk(int &x,int &y,int perm, vector<vector<int > > vv)
{
    int xx,yy;
    if(perm==1)
    {
        xx=x+2;
        yy=y+1;
        if(xx>=8 || yy>=8)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==2)
    {
        xx=x+1;
        yy=y+2;
        if(xx>=8 || yy>=8)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==3)
    {
        xx=x-1;
        yy=y+2;
        if(xx<0 || yy>=8)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==4)
    {
        xx=x-2;
        yy=y+1;
        if(xx<0 || yy>=8)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==5)
    {
        xx=x-2;
        yy=y-1;
        if(xx<0 || yy<0)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==6)
    {
        xx=x-1;
        yy=y-2;
        if(xx<0 || yy<0)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==7)
    {
        xx=x+1;
        yy=y-2;
        if(xx>=8 || yy<0)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    if(perm==8)
    {
        xx=x+2;
        yy=y-1;
        if(xx>=8 || yy<0)
            return 0;
        if(vv[xx][yy])
            return 0;
    }
    x=xx;
    y=yy;
    return 1;
}

void get(vector<vector<int > > &vv,int x,int y)
{
    static int p=1;
    /*static int cc=0;
    ++cc;
    if(cc>70)
        return;
    int a,b,c;
    for(a=0;a<8;a++)
    {
        for(b=0;b<8;b++)
        {
            if(vv[a][b]<10)
                cout<<"0"<<vv[a][b]<<" ";
            else
                cout<<vv[a][b]<<" ";
        }

        cout<<endl;
    }
    cout<<endl;
*/
    if(p==64)
        return;
    //cout<<x<<" "<<y<<endl;
    vv[x][y]=p;
    int a,b,c;
    b=x;c=y;
    bool s=0;
    for(a=1;a<=8;a++)
    {
        if(!chk(x,y,a,vv))
            continue;
        else
        {
            ++p;
            get(vv,x,y);
            if(vv[x][y])
                s=1;
            --p;
            x=b;y=c;
        }
    }
    if(!s)
        vv[x][y]=0;
    //vv[x][y]=0;

}

int main()
{
    int a,b,c;
    vector<int > v1(8,0);
    vector<vector<int > > vv(8,v1);
    get(vv,0,0);
    for(a=0;a<8;a++)
    {
        for(b=0;b<8;b++)
        {
            if(vv[a][b]<10)
                cout<<"0"<<vv[a][b]<<" ";
            else
                cout<<vv[a][b]<<" ";
        }

        cout<<endl;
    }
    cout<<endl;

}
