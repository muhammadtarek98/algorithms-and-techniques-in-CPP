#ifndef CUM_SUM_H
#define CUM_SUM_H
#include<bits/stdc++.h>
class cum_sum_2D{
public:
    void cumm_sum(int &n,int &m,std::vector<std::vector<int>> &pref);
    void calc_cumm_sum_row(std::vector<std::vector<int>> &pref);
    void calc_cumm_sum_col(std::vector<std::vector<int>> &pref);
    int range_sum(int &i,int &j,int &k,int &l,std::vector<std::vector<int>> &pref);

};
#endif //CUM_SUM_H
