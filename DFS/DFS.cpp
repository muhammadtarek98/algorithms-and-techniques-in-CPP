#include "DFS.h"
void DFS::dfs1(int &s,std::vector<std::vector<int>> &adj,std::vector<int> &vis)
{
    if(vis[s])
        return;
    vis[s]=1;
    for(auto &i:adj[s])
    {
        if(!vis[i])
        {
            dfs1(i,adj,vis);
        }
    }

}
void DFS::dfs2(long long &s,std::vector<std::vector<int>> &adj,std::vector<bool> &vis)
{
    vis[s]=true;
    for(int i=0;i<(int)adj[s].size();i++)
    {
        long long f=adj[s][i];
        if(!vis[f])
        {
            dfs2(f,adj,vis);
        }
    }
}