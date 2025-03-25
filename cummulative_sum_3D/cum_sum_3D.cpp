#include "cum_sum_3D.h"
void cum_sum_3D::cumm_sum(int &x,int &y,int &z,std::vector<std::vector<std::vector<int>>> &pref)
{
    for(int i=0;i<=x;i++)
    {
        pref[i][0][0]=0;
    }
    for(int i=0;i<=y;i++)
    {
        pref[0][i][0]=0;
    }
    for(int i=0;i<=z;i++)
    {
        pref[0][0][i]=0;
    }
}
void cum_sum_3D::calc_cumm_sum_x(std::vector<std::vector<std::vector<int>>> &pref)
{
    for(int i=1;i<(int)pref.size();i++)
    {
        for(int j=1;j<(int)pref[0].size();j++)

        {
            for(int k=1;k<(int)pref[0][0].size();k++)
            {
                pref[i][j][k]+=pref[i][j-1][k-1];
            }
        }
    }
}
void cum_sum_3D::calc_cumm_sum_y(std::vector<std::vector<std::vector<int>>> &pref)
{
    for(int i=1;i<(int)pref[0].size();i++)
    {
        for(int j=1;j<(int)pref.size();j++)

        {
            for(int k=1;k<(int)pref[0][0].size();k++)
            {
                pref[i][j][k]+=pref[i-1][j][k-1];
            }
        }
    }
}
void cum_sum_3D::calc_cumm_sum_z(std::vector<std::vector<std::vector<int>>> &pref)
{
    for(int i=1;i<(int)pref[0][0].size();i++)
    {
        for(int j=1;j<(int)pref[0].size();j++)

        {
            for(int k=1;k<(int)pref.size();k++)
            {
                pref[i][j][k]+=pref[i-1][j-1][k];
            }
        }
    }
}