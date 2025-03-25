#include<bits/stdc++.h>
#include "DSU.h"
#include "BFS.h"
#include "binary_search.h"
#include "cum_sum.h"
#include "cum_sum_3D.h"
#define format(q) setprecision(q)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP1(i,a,b) for (int i = a; i <= b; i++)
#define REP0(i,a,b) for (int i = a; i < b; i++)
using namespace std;
typedef vector<int> vi;
typedef vector<double>vd;
typedef vector<float>vf;
typedef vector<long long>vll;
const double pi=22.0/7.0;
const int MX=(int)((1e3))+5;
const int OOpos =(int)1e6;
const int OOneg =((int)(1e6))*-1;
const double eps=1.0/(1e7);
long long n,m;
int x,y,w;
int W[MX],p[MX];
int DP[MX][MX];
int knapsack(int i,int r)
{
    if(i==n)
    {
        return 0;
    }
    if(DP[i][r]!=-1)
    {
        return DP[i][r];
    }
    if(W[i]>r)
    {
        DP[i][r]=knapsack(i+1,r);/// leave the item
    }
    else
    {
        DP[i][r]=max(knapsack(i+1,r-W[i])+p[i],knapsack(i+1,r));///take the item
    }
    return DP[i][r];
}
/*
    give vector of vector a size of outside vector and inside vector
*/
vector<vector<char>> grid(MX+6,vector<char>(MX+6,'c'));
vector<vector<vector<char>>>g (MX,vector<vector<char>>(MX,vector<char>(MX,'c')));
/*
memset with vector
memset(v[0],-1,(int)v.size())
*/
char maper[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char num_char_map[]={'0','1','2','3','4','5','6','7','8','9'};
/*
int c=num_char_map[i]-'0';
    cout<<c;->i
*/
///4 direction
int dirx4[] = {0,0,-1,1};
int diry4[] = {-1,1,0,0};
///8 directions
int dirx8[]={0,0,1,-1,1,-1,1,-1};
int diry8[]={1,-1,0,0,1,-1,-1,1};
int adj[MX][MX];
int prv[MX][MX];
///unweighted edge list
struct unweightedge
{
    int s,d;
    unweightedge(int s,int d)
    {
        this->s=s;
        this->d=d;
    }
};
///weighted edge list
struct edgeweighted
{
    int src,des,weig;
    edgeweighted(int src,int des,int weig)
    {
        this->src=src;
        this->des=des;
        this->weig=weig;
    }
};
///in the grid
bool in(int &i,int &j,int &n)
{
    if(i>=0&&j>=0&&i<n&&j<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// 1D range sum 1 based array
int range_sum(int s,int e,vector<int> &pref)
{
    return pref[e]-pref[s-1];
}
///dijkstra
struct edge{
    int from,w,to;
    edge(int from,int to,int w)
    {
        this->from=from;
        this->to=to;
        this->w=w;
    }
    bool operator <(const edge &e) const
    {
        return w>e.w;
    }

};
int dijkstra2(vector<vector<edge>> &adj,int s,int d=-1)
{
    int sz=(int)adj.size();
    vector<int>dis(sz+2,OOpos);
    vector<int>prev(sz+2,-1);
    dis[s]=0;
    priority_queue<edge>q;
    q.push(edge(-1,s,0));
    while(!q.empty())
    {
        edge e=q.top();
        int cur_to=e.to,cur_from=e.from,cur_w=e.w;
        q.pop();
        if(cur_w>dis[cur_to])
        {
            continue;
        }
        prev[cur_to]=cur_from;
        for(int j=0;j<(int)adj[cur_to].size();j++)
        {
            edge f=adj[cur_to][j];
            int to=e.to,from=e.from,w=e.w;
            if(dis[to]>dis[from]+w)
            {
                f.w=dis[to]=dis[from]+w;
                q.push(f);
            }
        }
    }
    if(d==-1)
    {
        return -1;
    }
    return dis[d];
}
vector<int> dijkstra(long long &sr,long long &des,vector<vector<pair<long long,long long>>> &adj,long long &sz)///pair in adj is <node,weight>
{
    vector<int>par(sz+4,-1);
    vector<int>dis(sz+1,-1);
    set<pair<int,int>>s;///<total weight , node>
    s.insert({0,sr});
    while(!s.empty())
    {
        pair<int,int>p=*(s.begin());
        s.erase(p);
        int nod=p.second;
        int cost=p.first;
        if(dis[nod]!=-1)
        {
        continue;
        }
        dis[nod]=cost;
        for(int i=0;i<(int)adj[nod].size() ; i++)
            {
                pair<int,int>k=adj[nod][i];
                if(dis[k.first]==-1)
                {
                    par[k.first]=nod;
                    s.insert({cost+k.second,k.first});
                }
            }
    }
    return dis;
    vector<int>path;
    path.push_back(des);
    long long x=des;
    while(x!=sr)
    {
        x=par[x];
        path.push_back(x);
    }
    reverse(path.begin(),path.end());
    return path;

}
///build path
void path(int i,int j)
{
    if(i!=j)
    {
        path(i,prv[i][j]);
    }
    cout<<j<<" ";
}
///floyd
void floyd(int &n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {

                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}
///bellmanford
void bellmanford(vector<edgeweighted> &edgelist,int &n,int &src)
{
vector<int>dis(n,OOpos);
dis[src]=0;
for(int edges=0;edges<n-1;edges++)
{
    for(int i=0,r=0;i<(int)edgelist.size();i++,r=0)
    {
        edgeweighted nw=edgelist[i];
        int d=nw.des,s=nw.src,w=nw.weig;
        if(dis[d]>dis[s]+w)
        {
            dis[d]=dis[s]+w;
            r=1;
        }
        if(!r)
        {
           break;
        }
    }
}
}
/// path bellmanford
vector<int>bellmanfordpath(vector<edgeweighted> &edgelist,int &n,int &src)
{
vector<int>dis(n,OOpos);
vector<int>pre(n,-1);
dis[src]=0;
for(int edges=0;edges<n;edges++)
{
    for(int i=0,r=0;i<(int)edgelist.size();i++,r=0)
    {
        edgeweighted nw=edgelist[i];
        int d=nw.des,s=nw.src,w=nw.weig;
        if(dis[d]>dis[s]+w)
        {
            dis[d]=dis[s]+w;
            pre[d]=s;
            r=1;

        }
        if(!r)
        {
           break;
        }
    }
}
    reverse(pre.begin(),pre.end());
    return pre;
}
///cycle detection bellmanford
bool bellmanfordcd(vector<edgeweighted> &edgelist,int &n,int &src)
{
vector<int>dis(n,OOpos);
dis[src]=0;
for(int edges=0;edges<n;edges++)
{
    for(int i=0,r=0;i<(int)edgelist.size();i++,r=0)
    {
        edgeweighted nw=edgelist[i];
        int d=nw.des,s=nw.src,w=nw.weig;
        if(dis[d]>dis[s]+w)
        {
            dis[d]=dis[s]+w;
            r=1;
            if(edges==n-1)
            {
                return true;
            }
        }
        if(!r)
        {
           break;
        }
    }
}
return false;
}

void fast()
{
 #ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(int argc, char const *argv[])
{
    //fast();
    BFS obj1;
    my_binary_search obj2;
     return 0;
}
