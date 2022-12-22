/*
  Peak element
Problem statement :  Given an array. Find index of peak element in array.
  Peak element :  it should be greater than its both neighbours. (for end element (i=0||i=n-1) it has only 1 neighbour);
  E.g. [5,10,20,15]          output = 2 (20 is peak element)
       [10,20,15,2,23,90,67]      output = 1/5 (both are correct)    (20,90 is peak element)
       [10,20,30,40,50]        output=4  (50 is peak element)

 
  Criterion : 
  a) mid as answer;
    --> just check a[mid] with a[mid-1] and a[mid+1]
      if a[mid] > both a[mid-1]&a[mid+1] then mid is our answer;
      and if mid is 0 or n-1 then compare it with just only neighbour.
      crieterion is developed;

  b) to discard either left or right half;
      5 10 20 15
      Here l=0 , h=3  then mid=1;
      Now since a[mid]=10  , is not peak element;
      hence Now discard either left or right half;

      let's develop that crieterion. (here we will discard half based on neighbour of mid)
      Here 10 is not peak.
      It means one of the neighbour of mid (10) is > 10 (that's why it is not answer)
      Here both neighbour are greater than 10.

      Let's see 5 ,   here 5<10 (hence definitely 5 will not be an peak element irrespective of left neighbour of 5);
      Let's see 20,   as 20<10 (hence 20 can be peak element based on right neighbour of 20);

      Hence right side seems most promising.
      Hence we will go to right side;


      Hence whichever neighbour is greater than a[mid] , we will move in that direction (by observation)
*/

#include<bits/stdc++.h>
using namespace std;

int peak_element(int a[],int n)
{
     int low=0; int high=n-1;
     while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid>0&&mid<n-1)
        {
           if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
           {
                return mid;
           }
           else if(a[mid+1]>a[mid])  //we will move in right half;
           {
               low=mid+1;
           }
            else
           {
              high=mid-1;
           }
        }
        else if(mid==0)  //edge case;
        {
            if(a[0]>a[1])
            return 0;

            return 1;   //why
        }
        else if(mid==n-1)
        {
            if(a[n-1]>a[n-2])
            return n-1;

            return n-2;   //why
        }
    }
    return -1;
}
int main()
{
    int a[4]={5,10,20,15}; int n=4;
    cout<<peak_element(a,4);
    return 0;
}