#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class llist
{
    private:
        struct node
        {
            int val;
            node* next;
        };
    public:
        node* head;
        llist();
        ~llist();
        void del(node* );
        void add(node* ,int );
        void print(node* );
        void rreverse(node* );
};

llist:: llist()
{
    head=NULL;
}

llist:: ~llist()
{
    del(head);
    head=NULL;
}

void llist:: del(node* p)
{
    node* q=p;
    p=p->next;
    delete(q);
    cout<<"s ";
    if(p)
        del(p);
}

void llist:: add(node* p, int a)
{
    node* q;
    q=new node();
    q->val=a;
    if (!p)
    {
        p=q;
        head=p;
    }
    else
    {
        while(p->next)
            p=p->next;
        p->next=q;
    }
}

void llist:: print(node* p)
{
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int a, b, c;
    llist l1;
    l1.add(l1.head,5);
    l1.add(l1.head,6);
    l1.add(l1.head,6);
    l1.add(l1.head,1);
    l1.add(l1.head,89);
    l1.add(l1.head,2);
    l1.add(l1.head,7);
    l1.add(l1.head,7);
    l1.print(l1.head);
    l1.~llist();
    l1.print(l1.head);
}
