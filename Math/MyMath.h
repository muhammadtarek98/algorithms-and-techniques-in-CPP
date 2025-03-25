#ifndef MYMATH_H
#define MYMATH_H
#include<bits/stdc++.h>
class MyMath {
  public:
    MyMath(int MX);
    void sieve (int p,std::vector<int> sieve);
    int gcd(int x,int y);
    int Pow(int a,int p);
    bool Isprime(int &n);
    int bitcount(int x);
    int LCS(int i,int j,std::string &x,std::string &y);
    private:
        int MX;
        int **dp;

};



#endif //MYMATH_H
