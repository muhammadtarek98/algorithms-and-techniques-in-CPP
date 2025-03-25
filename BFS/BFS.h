#ifndef BFS_H
#define BFS_H

#include<bits/stdc++.h>


class BFS {
public:
    std::vector<long long>bfs2path(long long &sr,long long &sz,
                                  std::vector<std::vector<long long>> &adj,
                                  std::vector<bool> &vis,long long &des);
    std::vector<int> BFSPath(int &sr, int &des, std::vector<std::vector<int>> &adj,int &sz,std::vector<bool> &vis);
    std::vector<int>bfs1 (int &sr,int &sz,std::vector<std::vector<int>> &adj,std::vector<bool> &vis,int &des);
    std::vector<long long>bfs2(long long &sr,long long &sz,std::vector<std::vector<long long>> &adj,std::vector<bool> &vis,long long &des);

};



#endif //BFS_H
