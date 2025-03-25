#include "DSU.h"
void DSU::intial (int &sz , int a[] , int siz[])
{
    for(int i=1;i<=sz;i++)
    {
        a[i]=i;
        siz[i]=1;
    }
}
int DSU::lead(int v,int a[])
{
    if(v==a[v])
    {
        return v;
    }
    return a[v]=lead(a[v],a);
}
bool DSU::samelead(int x,int y,int a[])
{
    int l1=lead(x,a);
    int l2=lead(y,a);
    return l1==l2;
}
void DSU::mergeg(int x,int y,int a[],int siz[])
{
    int l1=lead(x,a);
    int l2=lead(y,a);
    if(l1==l2)
    {
        return;
    }
    if(siz[l1]>siz[l2])
    {
        a[l2]=l1;
        siz[l1]+=siz[l2];
    }
    else if(siz[l2]>siz[l1])
    {
        a[l1]=l2;
        siz[l2]+=siz[l1];
    }
}