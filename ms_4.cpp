#include<iostream>
#include<stdio.h>
#include<vector>
#include<deque>
#include<climits>
#include<map>
#include<cmath>

using namespace std;

class bst
{
    private:
        struct node
        {
            int val;
            node* lchild;
            node* rchild;
        };
    public:
        node* root;
        bst();
        ~bst();
        void del(node* );
        void add(node* ,int );
        void inorder(node* );
        void preorder(node* );
        void postorder(node* );
        void convert(vector<int > ,int ,int );
        bool f_search(node* ,int );
        void l_order();
        void p_paths(node* );
        int t_count(node* );
        int t_height(node* );
        void i_inorder();
        void i_preorder();
        void i_postorder();
        int lca(node* ,int ,int );
        int diameter(node* );
        int h_balanced(node* );
        int n_leaf(node* );
};

bst:: bst()
{
    root=NULL;
}

bst:: ~bst()
{
    del(root);
    root=NULL;
    cout<<endl;
}

void bst:: del(node* p)
{
    if(!p)
        return;
    del(p->lchild);
    del(p->rchild);
    delete(p);
    cout<<"s"<<" ";
}

void bst:: add(node* p,int a)
{
    if(root==NULL)
    {
        node* n;
        n=new node;
        n->lchild=NULL;
        n->rchild=NULL;
        n->val=a;
        root=n;
        return;
    }
    if(p->val>a && p->lchild)
        add(p->lchild,a);
    else if(p->val>a && !p->lchild)
    {
        node* n;
        n=new node;
        n->lchild=NULL;
        n->rchild=NULL;
        n->val=a;
        p->lchild=n;
    }
    else if(p->val<a && p->rchild)
        add(p->rchild,a);
    else if(p->val<a && !p->rchild)
    {
        node* n;
        n=new node;
        n->lchild=NULL;
        n->rchild=NULL;
        n->val=a;
        p->rchild=n;
    }
}

void bst:: inorder(node* p)
{
    if(!p)
        return;
    inorder(p->lchild);
    cout<<p->val<<" ";
    inorder(p->rchild);
}

void bst:: preorder(node* p)
{
    if(!p)
        return;
    cout<<p->val<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
}

void bst:: postorder(node* p)
{
    if(!p)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->val<<" ";
}

void bst:: convert(vector<int > v1,int a,int b)
{
    if(a==b)
    {
        add(this->root,v1[a]);
        return;
    }
    else if(a==b-1)
    {
        add(this->root,v1[a]);
        add(this->root,v1[b]);
        return;
    }
    int mid=(a+b)/2;
    add(this->root,v1[mid]);
    convert(v1,a,mid-1);
    convert(v1,mid+1,b);
}

bool bst:: f_search(node* p,int x)
{
    if(!p)
        return 0;
    if(p->val==x)
        return 1;
    return f_search(p->lchild,x) || f_search(p->rchild,x);
}

int bst:: t_count(node* p)
{
    if(!p)
        return 0;
    return t_count(p->lchild)+t_count(p->rchild)+1;
}

int bst:: t_height(node* p)
{
    if(!p)
        return 0;
    int l,r;
    l=t_height(p->lchild);
    r=t_height(p->rchild);
    if(l>r)
        return l+1;
    return r+1;
}

void bst:: l_order()
{
    node* p=root;
    node* q;
    deque<node* > d1;
    d1.push_back(p);
    d1.push_back(NULL);
    while(1)
    {
        if(d1.size()==1 && !d1.back())
            break;
        if(!d1.back())
        {
            d1.pop_back();
            cout<<endl;
            d1.push_front(NULL);
        }
        else
        {
            q=d1.back();
            d1.pop_back();
            cout<<q->val<<" ";
            if(q->lchild)
                d1.push_front(q->lchild);
            if(q->rchild)
                d1.push_front(q->rchild);
        }
    }
}

void bst:: p_paths(node* p)
{
    static vector<node* > v1;
    v1.push_back(p);
    if(!p->lchild && !p->rchild)
    {
        for(int a=0;a<v1.size();a++)
            cout<<v1[a]->val<<" ";
        cout<<endl;
        v1.pop_back();
        return;
    }
    if(p->lchild)
    p_paths(p->lchild);
    if(p->rchild)
    p_paths(p->rchild);
    v1.pop_back();
}

int bst:: lca(node* p,int a,int b)
{
    if(!p)
        return 0;
    if((p->val==a || p->val==b) || (lca(p->lchild,a,b) && lca(p->rchild,a,b)))
        return p->val;
    return (lca(p->lchild,a,b) + lca(p->rchild,a,b));
}

int bst:: diameter(node* p)
{
    static int mmax=0;
    if(!p)
        return 0;
    if(diameter(p->lchild)+diameter(p->rchild)+1>mmax)
        mmax=diameter(p->lchild)+diameter(p->rchild)+1;
    if(p==root)
        return mmax;
    return max(diameter(p->lchild),diameter(p->rchild))+1;
}

void bst:: i_inorder()
{
    vector<node* > v1;
    node* p=root;
    node* q;
    while(1)
    {
        if(p)
        {
            v1.push_back(p);
            p=p->lchild;
        }
        else
        {
            q=v1.back();
            v1.pop_back();
            cout<<q->val<<" ";
            if(v1.size()==0 && !q->rchild)
                break;
            p=q->rchild;
        }
    }
}

void bst:: i_preorder()
{
    node* p=root;
    vector<node* > v1;
    v1.push_back(p);
    while(v1.size())
    {
        p=v1.back();
        v1.pop_back();
        cout<<p->val<<" ";
        if(p->rchild)
            v1.push_back(p->rchild);
        if(p->lchild)
            v1.push_back(p->lchild);
    }
}

void bst:: i_postorder()
{
    node* p=root;
    vector<node* > v1;
    vector<node* > v2;
    v1.push_back(p);
    while(v1.size())
    {
        p=v1.back();
        v1.pop_back();
        v2.push_back(p);
        if(p->lchild)
            v1.push_back(p->lchild);
        if(p->rchild)
            v1.push_back(p->rchild);

    }
    while(v2.size())
    {
        p=v2.back();
        v2.pop_back();
        cout<<p->val<<" ";
    }
}

int bst:: h_balanced(node* p)
{
    if(!p)
        return 0;
    int lh,rh;
    lh=h_balanced(p->lchild);
    rh=h_balanced(p->rchild);
    if(p==root)
    {
        if(lh==-1 || rh==-1 || abs(lh-rh)>1)
            return 0;
        return 1;
    }
    if(lh==-1 || rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    return max(lh,rh)+1;
}

int bst::n_leaf(node* p)
{
    if(!p->lchild && !p->rchild)
        return 1;
    int l,r;
    l=0;r=0;
    if(p->lchild)
        l=n_leaf(p->lchild);
    if(p->rchild)
        r=n_leaf(p->rchild);
    return l+r;
}

int main()
{
    int a,b,c;
    bst b1,b2;
    b1.add(b1.root, 5);
    b1.add(b1.root, 7);
    b1.add(b1.root, 9);
    b1.add(b1.root, 8);
    b1.add(b1.root, 6);
    b1.add(b1.root, 2);
    b1.add(b1.root, 1);
    b1.add(b1.root, 4);
    b1.add(b1.root, 3);
    b1.inorder(b1.root);
    cout<<endl;
    b1.preorder(b1.root);
    cout<<endl;
    b1.postorder(b1.root);
    cout<<endl;
    vector<int > v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    b2.convert(v1,0,v1.size()-1);
    b2.inorder(b2.root);
    cout<<endl<<b1.f_search(b1.root,10)<<" "<<b1.f_search(b1.root,1)<<" "<<b1.t_count(b1.root)<<" "<<b1.t_height(b1.root);
    cout<<endl;
    b1.l_order();
    cout<<endl;
    b2.l_order();
    cout<<endl<<endl;
    b1.p_paths(b1.root);
    cout<<endl;
    b2.p_paths(b2.root);
    cout<<endl<<b1.lca(b1.root,6,2)<<endl;
    cout<<b1.diameter(b1.root)<<endl<<b2.diameter(b2.root)<<endl;
    b1.i_inorder();
    cout<<endl<<b1.h_balanced(b1.root)<<endl<<b2.h_balanced(b2.root)<<endl;
    cout<<b1.n_leaf(b1.root)<<endl<<b2.n_leaf(b2.root)<<endl;
    //cout<<b1.succ(1)<<" ";//<<b1.succ(3)<<" "<<b1.succ(6)<<" "<<b1.succ(8)<<" "<<endl;
}
