#ifndef DSU_H
#define DSU_H
#include <bits/stdc++.h>
class DSU {
public:
    void intial (int &sz , int a[] , int siz[]);
    int lead(int v,int a[]);
    bool samelead(int x,int y,int a[]);
    void mergeg(int x,int y,int a[],int siz[]);

};



#endif //DSU_H
