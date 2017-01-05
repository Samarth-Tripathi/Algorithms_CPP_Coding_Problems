#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<climits>
#include<cmath>

using namespace std;

class graph
{
    private:
        int n;
        vector<vector<int > > g;
    public:
        graph(int );
        ~graph();
        void add_e(int ,int );
        void BFS(int );
        void rdfs(int ,vector<int > &,vector<int > &,vector<int > &,vector<int > &,int );
        void DFS(int );

};

graph:: graph(int p)
{
    n=p-1;
    vector<int > v;
    g.assign(n+1,v);
}

graph:: ~graph()
{
    int a,b;
    for(a=0;a<g.size();a++)
        g[a].clear();
    g.clear();
}

void graph:: add_e(int a,int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void graph:: BFS(int p)
{
    int a,b,c;
    vector<bool > visit;
    vector<int > parent;
    vector<int > dist;
    visit.assign(n+1,0);
    parent.assign(n+1,0);
    dist.assign(n+1,INT_MAX);
    deque<int > v;
    v.push_back(p);
    visit[p]=1;
    dist[p]=0;
    while(v.size())
    {
        b=v.back();
        v.pop_back();
        for(a=0;a<g[b].size();a++)
        {
            if(visit[g[b][a]])
                continue;
            visit[g[b][a]]=1;
            dist[g[b][a]]=dist[b]+1;
            parent[g[b][a]]=b;
            v.push_front(g[b][a]);
        }
        cout<<b<<" "<<visit[b]<<" "<<parent[b]<<" "<<dist[b]<<endl;
    }
}

void graph:: rdfs(int p,vector<int > &visit,vector<int > &parent,vector<int > &dtime,vector<int > &ftime,int par)
{
    static int t=0;
    if(visit[p])
        return;
    visit[p]=1;
    parent[p]=par;
    dtime[p]=t;
    t++;
    int a;
    for(a=0;a<g[p].size();a++)
        rdfs(g[p][a],visit,parent,dtime,ftime,p);
    visit[p]=2;
    ftime[p]=t;
    t++;
    //cout<<p<<" "<<visit[p]<<" "<<parent[p]<<" "<<dtime[p]<<" "<<ftime[p]<<" "<<par<<endl;
}

void graph:: DFS(int p)
{
    int a,b,c;
    vector<int > visit(n+1,0);
    vector<int > parent(n+1,0);
    vector<int > dtime(n+1,INT_MAX);
    vector<int > ftime(n+1,INT_MAX);
    rdfs(p,visit,parent,dtime,ftime,0);
    for(a=0;a<=n;a++)
        cout<<a<<" "<<visit[a]<<" "<<parent[a]<<" "<<dtime[a]<<" "<<ftime[a]<<endl;
}

int main()
{
    graph g1(5);
    g1.add_e(1,2);
    g1.add_e(1,4);
    g1.add_e(0,2);
    g1.add_e(3,2);
    g1.add_e(0,3);
    g1.BFS(0);
    cout<<endl;
    g1.BFS(4);
    cout<<endl;
    g1.DFS(0);

}
