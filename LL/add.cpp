#include<iostream>
#include<stdio.h>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
    int a,x,y,z,b;
    list<int > l1,l2,l3,lf;
    list<int > ::iterator i1,i2,i3;
    l1.push_back(5);l1.push_back(2);l1.push_back(1);l1.push_back(7);l1.push_back(6);
    l2.push_back(5);l2.push_back(7);l2.push_back(6);
    l3.push_back(2);l3.push_back(7);l3.push_back(7);l3.push_back(6);
    l1.reverse();l2.reverse();l3.reverse();
    int carry=0;
    int n=max(l1.size(),max(l2.size(),l3.size()));
    i1=l1.begin();i2=l2.begin();i3=l3.begin();
    for(a=0;a<n;a++)
    {
       if(i1!=l1.end())
          {x=*i1;i1++;}
       else
          x=0;
       if(i2!=l2.end())
          {y=*i2;i2++;}
       else
          y=0;
       if(i3!=l3.end())
          {z=*i3;i3++;}
       else
          z=0;
       b=x+y+z;
       b+=carry;
       carry=b/10;
       b=b%10;
       lf.push_back(b);
    }
    lf.reverse();
    copy(lf.begin(),lf.end(),ostream_iterator<int >(cout," "));

}
