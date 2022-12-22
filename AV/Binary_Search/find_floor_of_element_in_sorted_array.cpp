#include<bits/stdc++.h>
using namespace std;

int floor_of_element_in_array(int a[],int n,int key)
{
    int low=0;
    int high=n-1;
    int result=INT_MIN;
    while(low<=high)
    {
      int mid=low + ((high-low)/2);

      if(a[mid]==key)
      {
          return a[mid];
        //alter here you can write these two statments instead of return a[mid];
        //result=a[mid]; 
        //break;  //(here break would be imp in that case otherwise infinite loop);
      }
      if(a[mid]<key)
      {
         result=max(result,a[mid]);  //as here a[mid] <key hence it can be answer (it is a candidate)
         low=mid+1;
      }
      else if(a[mid]>key)
      {
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
    cout<<floor_of_element_in_array(arr,n,i)<<endl;      //clearly floor of key=1 to 15  are giving correct output.
    
    return 0;
}


/* 
 Problem statement :
 Find floor of an element in a sorted array.

  
  Floor : floor(7.8)=7;  ceil(7.8)=8;

  New defination of floor :
   floor of an element k in a sorted array.
     1. if that elmeent (k) is exist in array then floor is itself.
     2. if k not exist in array, greatest element smaller than k in array.

*/

