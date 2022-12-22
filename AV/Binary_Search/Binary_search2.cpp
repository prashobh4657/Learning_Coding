/*Given sorted array. Given target. Returns its index on which it is present in array. */

// Time complexity : logn (base 2)

#include<bits/stdc++.h>
using namespace std;

int search(int a[],int n,int key)
{
     int low=0; int high=n-1;
    while(low<=high)
    {
        int mid=low + (high-low)/2;       
    // Here mid=(low+high)/2 = low + z (remember like this)  (then z = (low+high)/2 - low = (high-low)/2 hence mid = low + (high-low)/2);
    // Reason : If low and high both tend to int range , then low+high will make overflow , in that (low+high)/2 will give invalid answer.
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]<key)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;

}
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int key; cin>>key;

   cout<<search(a,n,key);
    return 0;
}