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
            node* nxt;
        };
    public:
        node* head;
        llist();
        ~llist();
        void add(node* ,int );
        void pprint(node* );
        void del(node* );
        void rev();
        void rev2(node* ,node* );
        bool palin(node** ,node* );
        bool ispalin();
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
    p=p->nxt;
    delete(q);
    cout<<"s ";
    if(p)
        del(p);
}

void llist:: add(node* p,int x)
{
    if(!head)
    {
        node* n;
        n=new node;
        n->val=x;
        n->nxt=NULL;
        head=n;
        return;
    }
    if(p->nxt)
    {
        add(p->nxt,x);
        return;
    }
    node* n;
    n=new node;
    n->val=x;
    n->nxt=NULL;
    p->nxt=n;
}

void llist:: pprint(node* p)
{
    if(!p)
        return;
    cout<<p->val<<" ";
    pprint(p->nxt);
}

void llist:: rev()
{
    node* p,*q,*r;
    p=head;q=head;
    r=head->nxt;
    p->nxt=NULL;
    while(r)
    {
        q=r;
        r=r->nxt;
        q->nxt=p;
        p=q;
    }
    head=p;
}

void llist:: rev2(node* p,node* prev)
{
    if(!p->nxt)
    {
        head=p;
        p->nxt=prev;
        return;
    }
    rev2(p->nxt,p);
    p->nxt=prev;
}

bool llist:: palin(node** l,node* r)
{
    if(!r)
        return 1;
    bool p= palin(l,r->nxt);
    cout<<(*l)->val<<" "<<r->val<<endl;
    if(p)
    {
        if((*l)->val==r->val)
        {
            *l=(*l)->nxt;
            return 1;
        }
        *l=(*l)->nxt;
        return 0;
    }
    return 0;
}

bool llist:: ispalin()
{
    node* p=head;
    bool q=palin(&head,head);
    head=p;
    return q;
}

int main()
{
    llist l1;
    l1.add(l1.head,5);
    l1.add(l1.head,8);
    l1.add(l1.head,6);
    l1.add(l1.head,1);
    l1.add(l1.head,5);
    l1.add(l1.head,6);
    l1.add(l1.head,8);
    l1.add(l1.head,5);
    l1.pprint(l1.head);
    cout<<endl;
    l1.rev();
    l1.rev2(l1.head,NULL);
    l1.pprint(l1.head);
    cout<<endl;
    cout<<l1.ispalin()<<endl;
}
