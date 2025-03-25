#ifndef CUM_SUM_3D_H
#define CUM_SUM_3D_H
#include <bits/stdc++.h>

class cum_sum_3D {
public:
    void cumm_sum(int &x,int &y,int &z,std::vector<std::vector<std::vector<int>>> &pref);
    void calc_cumm_sum_x(std::vector<std::vector<std::vector<int>>> &pref);
    void calc_cumm_sum_y(std::vector<std::vector<std::vector<int>>> &pref);
    void calc_cumm_sum_z(std::vector<std::vector<std::vector<int>>> &pref);

};



#endif //CUM_SUM_3D_H
