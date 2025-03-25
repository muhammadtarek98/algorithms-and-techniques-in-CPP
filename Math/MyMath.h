#ifndef MYMATH_H
#define MYMATH_H
#include<bits/stdc++.h>
const int MX=(int)((1e3))+5;
class MyMath {
  public:
    void sieve (int p,std::vector<int> sieve);
    int gcd(int x,int y);
    int Pow(int a,int p);
    bool Isprime(int &n);
    int bitcount(int x);
    int LCS(int i,int j,std::string &x,std::string &y);
    private:
        int dp[MX][MX];
};



#endif //MYMATH_H
