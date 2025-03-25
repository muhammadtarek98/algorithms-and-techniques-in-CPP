#include "binary_search.h"
int my_binary_search::BINARY_SEARCH_recursive(long long k,int low,int high,std::vector<long long> &a){
    if(high<low)
    {
        return -1;
    }
    else
    {
        int mid=low+(high-low)/2;
        if(a[mid]>k)
        {
            return BINARY_SEARCH_recursive(k,low,mid-1,a);
        }
        else if(a[mid]<k)
        {
            return BINARY_SEARCH_recursive(k,mid+1,high,a);
        }
        else
        {
            return mid;
        }
    }
}
int my_binary_search::BINARY_SEARCH_iterative(long long k,int low,int high,std::vector<long long> &a){
    while(high>=low)
    {
        int mid=low+(high-low)/2;
        if(a[mid]<k)
        {
            low=mid+1;
        }
        else if(a[mid]>k)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }

    }
    return -1;
}
