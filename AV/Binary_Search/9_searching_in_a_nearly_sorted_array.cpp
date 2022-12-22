/* searching in nearly sorted array: This array is nearly sorted. It means any element in array which is supposed to be at ith index, 
  it is currently can be present at i-1, i ,i+1 index (in nearly sorted array). */ 

#include<bits/stdc++.h>
using namespace std;

int search(int a[],int n,int key)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid= (low+high)/2;
           
           if(a[mid]==key)
           return mid;
           if(a[mid-1]==key  &&  mid-1>=low)
           return mid-1;
           if(a[mid+1]==key && mid+1<=high)
           return mid+1;

        //it means now key is not at mid,mid-1,mid+1 hence discarding either left or right half.
        if(key<a[mid])
           high=mid-2;
        else
           low=mid+2;
    }
    return -1;
    
}

int main()
{   int a[]={5,10,20,50,40};
        
    int key=10;
    cout<<search(a,5,key);  // will print index of key;
    return 0;
}