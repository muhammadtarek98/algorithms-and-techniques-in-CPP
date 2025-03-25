#include"cum_sum.h"
void cum_sum_2D::cumm_sum(int &n,int &m,std::vector<std::vector<int>> &pref)
{
    for(int i=0;i<=n;i++)
    {
        pref[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        pref[0][i]=0;
    }
}
void cum_sum_2D::calc_cumm_sum_row(std::vector<std::vector<int>> &pref)
{
    for(int i=1;i<(int)pref.size();i++)
    {
        for(int j=1;j<(int)pref[0].size();j++)
        {
            pref[i][j]+=pref[i][j-1];
        }
    }
}
void cum_sum_2D::calc_cumm_sum_col(std::vector<std::vector<int>> &pref)
{
    for(int i=1;i<(int)pref[0].size();i++)
    {
        for(int j=1;j<(int)pref.size();j++)
        {
            pref[i][j]+=pref[i-1][j];
        }
    }
}
int cum_sum_2D::range_sum(int &i,int &j,int &k,int &l,std::vector<std::vector<int>> &pref)
{
    return pref[k][l]-pref[k][j-1]-pref[i-1][l]+pref[i-1][j-1];
}