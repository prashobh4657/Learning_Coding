#include<bits/stdc++.h>
using namespace std;
int first_occurrence(int a[],int n,int key,int low,int high)  
{
    while(low<=high)
    {
        int mid = low + ((high-low)/2);

        if(a[mid]==key)
        {
           if(a[mid]>a[mid-1])  
           return mid;
           else
           high=mid-1; 
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
    int a[10000000]; //infinite array.  (sorted)
    int low=0; int high=1; //let initially high=1;
    int key=1;
    while(key>a[high])
    {
        low=high;
        high=2*high;
    }
    //Now key<a[high]   hence now key is lie b/w index=low and high.
    //Now appplying binary search to find first occurrence of 1 in range [low-high];
    first_occurrence(a,10000000,key,low,high); //video5 function
    return 0;
}
/*
 Problem statement: 
  Given infinite binary sorted array (array will have only 0 and 1).
  Look like this  00000000000(x zeroes)....111111111(y 1's)
  x+y=infinite;

 Find index of first 1 in this array;

 Breakdown into subproblems:
   1. We have already solved first occurrence of an elemeent in sorted array;
   2. We have already solved a problem involved infinite array;
   
  Here since it is infinite Hence we don't know high , hence keep low=0, high=1;
  Now make key lie b/w low and high.
  Then apply first_occurrence_concept in range [low-high];
*/