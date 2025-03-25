#include "MyMath.h"
MyMath::MyMath(int MX):MX(MX)
{
    this->dp=new int *[MX];
    for(int i=0;i<MX;i++)
    {
        this->dp[i]=new int[MX];
    }
    for(int i=0;i<MX;i++)
    {
        for(int j=0;j<MX;j++)
        {
            this->dp[i][j]=0;
        }
    }
}

void MyMath::sieve (int p,std::vector<int> sieve)
{
    int n=(int)sieve.size();
    memset(&sieve[0],1,n);
    sieve[0]=sieve[1]=0;
    for(int i=2;i*i<=p;i++)
    {
        if(sieve[i])
        {
            for(int j=i*i;j<=p;j+=i)
            {
                sieve[j]=false;
            }
        }
    }

}
///GCD
int MyMath:: gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    return gcd(y,x%y);

}
/*
get the result of a power p
*/
int MyMath::Pow(int a,int p)
{
    if(p==0)
    {
        return 1;
    }
    int sq=Pow(a,p/2);
    if(p%2==1)
    {
        sq=sq*a;
    }
    return sq;
}
bool MyMath::Isprime(int &n)
{
    if(n<2)
    {
        return 0;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
///bit=1 count
int MyMath::bitcount(int x)
{
    int c=0;
    while(x)
    {
        x&=(x-1);
        c++;
    }
    return c;
}
int MyMath::LCS(int i,int j,std::string &x,std::string &y)
{
    if(i==(int)x.size()||j==(int)y.size())
        return 0;
    if(this->dp[i][j]!=-1)
        return this->dp[i][j];
    if(x[i]==y[j])
        return this->dp[i][j]=LCS(i+1,j+1,x,y)+1;
    return this->dp[i][j]=std::max(LCS(i,j+1,x,y),LCS(i+1,j,x,y));
}