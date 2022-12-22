#include<bits/stdc++.h>
using namespace std;

int ceil_of_element_in_array(int a[],int n,int key)
{
    int low=0;
    int high=n-1;
    int result=INT_MAX;
    while(low<=high)
    {
      int mid=low + ((high-low)/2);
      if(a[mid]==key)
      {
          return a[mid];
      }
      if(a[mid]<key)
      {
         low=mid+1;
      }
      else if(a[mid]>key)
      {
         result=min(result,a[mid]); 
         high=mid-1;
      }
    }
    return result;
}
int main()
{   
    int arr[]={1,2,3,4,5,7,9,10,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<15;i++)
    cout<<ceil_of_element_in_array(arr,n,i)<<endl;      //clearly floor of key=1 to 15  are giving correct output.
    
    return 0;
}



/*
 Ceil of an element (k) in a sorted array: smallest element greater or equal to k;
*/