#include "BFS.h"
std::vector<int> BFSPath(int &sr, int &des, std::vector<std::vector<int>> &adj,int &sz,std::vector<bool> &vis)
{
    std::vector<int> par(sz,-1);
    std::vector<int> dis(sz,-1);
    std::queue<int> q;
    q.push(sr);
    dis[sr]=0;
    int depth=0,cur=sr,szq=1;
    bool flag=true;
    for(;flag&&!q.empty();depth++,szq=(int)q.size())
    {
        while(flag &&szq--)
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<(int)adj[cur].size();i++)
            {
                int f=adj[cur][i];
                if(dis[f]==-1)
                {
                    q.push(f);
                    dis[f]=depth+1;
                    par[f]=cur;
                }
                if(f==des)
                {
                    flag=false;
                    break;
                }
            }
        }
    }
    std::vector<int>pathl;
    while(des!=-1)
    {
        pathl.push_back(des);
        des=par[des];
    }

    reverse(pathl.begin(),pathl.end());
    return pathl;
}

std::vector<int>bfs1 (int &sr,int &sz,std::vector<std::vector<int>> &adj,std::vector<bool> &vis,int &des)
{
    std::vector<int> dis(sz,-1);
    std::queue<int>q;
    q.push(sr);
    dis[sr]=0;
    int depth=0,cur=sr,szq=1;
    for(;!q.empty();depth++,szq=(int)q.size())
    {
        while(szq--)
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<(int)adj[cur].size();i++)
            {
                int f=adj[cur][i];
                if(dis[cur]==-1)
                {
                    q.push(f);
                    dis[f]=depth+1;
                }
            }
        }

    }
    return dis;
}

std::vector<long long>bfs2(long long &sr,long long &sz,std::vector<std::vector<long long>> &adj,std::vector<bool> &vis,long long &des)
{
    std::vector<long long>dis(sz,-1);
    vis[sr]=true;
    dis[sr]=0;
    std::queue<long long>q;
    q.push(sr);
    while(!q.empty())
    {
        long long nod=q.front();
        q.pop();
        for(int i=0;i<(int)adj[nod].size();i++)
        {
            long long a=adj[nod][i];
            if(dis[a]==-1)
            {
                q.push(a);
                dis[a]=dis[nod]+1;
                vis[a]=true;
            }
        }
    }
    return dis;
}
std::vector<long long>bfs2path(long long &sr,long long &sz,std::vector<std::vector<long long>> &adj,std::vector<bool> &vis,long long &des)
{
    std::vector<long long>dis(sz,-1);
    std::vector<long long>par(sz);
    vis[sr]=true;
    dis[sr]=0;
    par[sr]=sr;
    std::queue<long long>q;
    q.push(sr);
    while(!q.empty())
    {
        long long nod=q.front();
        q.pop();
        for(int i=0;i<(int)adj[nod].size();i++)
        {
            long long a=adj[nod][i];
            if(dis[a]==-1)
            {
                q.push(a);
                par[a]=nod;
                dis[a]=dis[nod]+1;
                vis[a]=true;
            }
        }
    }
    std::vector<long long>pathl;
    pathl.push_back(des);
    long long x=des;
    while(x!=sr)
    {
        x=par[x];
        pathl.push_back(x);
    }
    reverse(pathl.begin(),pathl.end());
    return pathl;
}