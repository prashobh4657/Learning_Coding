#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v,int val, int low, int high)
{
    if(low>high)
    return -1;

    int mid=low+ (high-low)/2;

    if(v[mid]==val)
    return mid;

    if(v[mid]>val)
    return binary_search(v,val,low,mid-1);
    else
    return binary_search(v,val,mid+1,high);
}
int main()
{  
    vector <int> v={1,2,4,5,6};
    cout<<binary_search(v,-10,0,4);
    return 0;
}