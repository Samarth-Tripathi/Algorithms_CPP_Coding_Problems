#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    int a,b,c;
    string s1="abcdefg";
    string s2;
    s2=s1;
    cout<<s2<<endl;
    //getline(cin,s2);
    //cout<<s2<<endl;
    char ch1[10]="hcmyw";
    char ch2[]="kdmsancd";
    cout<<*ch2<<endl;
    //char ch3[];
    //ch3 = (char ) malloc(15);
    //strcpy(ch2,ch3);
    char *chh1;
    chh1 = (char* ) malloc(15);
    strcpy(chh1,ch1);
    //*(p++) (*p)++
    cout<<ch1<<" "<<ch2<<" "<<*chh1<<" "<<*(++chh1)<<" "<<--*chh1<<endl;
    chh1[3]='s';
    while(*chh1)
    {
        cout<<*chh1<<" ";
        chh1++;
    }
    const char *c1=s1.c_str();
    cout<<endl<<*c1<<" "<<s1;
    c1++;
    cout<<*c1<<endl;
    string sp1,sp2;
    sp1="mnuj";
    char *pc2="bbhcu";
    //pc2[0]='h';
    char *pc1;
    pc1="glonc";
    sp2=string(pc2);
    string sp3(pc1);
    cout<<sp2<<" "<<sp3;
    /*pc1=new char[sp1.length()+1];
    copy(sp1.begin(),sp2.end(),pc1);
    pc1[sp1.length()]='\0';*/

}
