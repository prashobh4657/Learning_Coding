/* Determine first occurence of a element in sorted array return its index  (duplicate will cause problem)
  for e.g. 2 4 10 10 10 18 20  
    key=10
    ans =2;
    */

#include<bits/stdc++.h>
using namespace std;

// these are codes for first occurrence.

int binary_search_by_aditya(int a[],int n,int key) //first occurrence
{

    int low=0;
    int high=n-1;
    int res=-1;  //if not found then return -1;
    while(low<=high)
    {
        int mid = low + ((high-low)/2);

        if(a[mid]==key)
        {
            res=mid;   //store this occurence in result variable;
            high=mid-1;    //keep searching in left half;
        }
        else if(a[mid]>key)
        high=mid-1;
        else
        low=mid+1;

    }
    return res;  

}
//you can write last occurrence code as well;
//aditya verma last occurrence code is same as function " int binary_search_by_aditya(int a[],int n,int key)" and he did modification in this itself.



//i though by myself completely this code (BUT DON"T learn this code) (This code fails in most of the test cases)
// like you are accessing mid-1 and mid+1 etc. in that you also need to apply conidtion like is mid-1>=0 and mid+1<=n-1 and all that
// i have tried on leetcode , these both codes which are written by yourself are failing in some testcases , 
//for handling that  we can  apply some condition of if-else (BUt wo tujhe yaad nhi rahengi) (so its better to learn aditya verma code)
int first_occurrence(int a[],int n,int key)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid = low + ((high-low)/2);        //imp to avoid integer overflow        ;mid= (low+high)/2 in this case low+high may be v.large and cause integer overflow;

        if(a[mid]==key)
        {
           if(a[mid]>a[mid-1])  //it is really its first occurence
           return mid;
           else
           high=mid-1;  //keep searching in left half of array;
        }
        else if(a[mid]>key)
        high=mid-1;
        else
        low=mid+1;

    }
    return -1;  //if not found;
}
int last_occurrence(int a[],int n,int key)
{
    int low=0; int high=n-1;
    while(low<=high)
    {
        int mid=low+((high-low)/2);
        if(a[mid]==key)
        {
            if(a[mid]<a[mid+1])
            return mid;
            else
            low=mid+1;
        }
        else if(a[mid]>key)
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n; 
    int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];

    int key;
    cin>>key;

    cout<<first_occurrence(a,n,key)<<endl;
    cout<<last_occurrence(a,n,key)<<endl;
  // cout<<binary_search_by_aditya(a,n,key);
    return 0;
}