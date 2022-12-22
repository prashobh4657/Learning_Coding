/*
 Problem Statement :  
   Find position of an element in an infinite sorted array.
   Generally this question asked into F2F interview.
   Think of the modification of Binary search
   Code

Similarity : 
 BinarySearch : low=0, high=n-1;
 This question : low=0, high = infinte-1 = exactly what to put here?

 Now , How high is initialized in this question? 

 The element which we are searching is always bounded by low and high. (in binary search)
 In binary search, we keep on smalling the size of boundary.

 Let in this question,
   let array = 1 2 3 4 5 6 7 8 9 10..........infinite,  let key=7;
   let low=0, high=1 (assume);
   Here key is not within range [low-high];
   hence we will try to make key lie in range.
   for that we will increment high.
   For that we will compare high and key.
   If key is larger then we will  make high=2*high and make low=previous high.
   again check whether key is enclose in range or not  (by comparing high and key again)
   if not then again do same thing
   otherwise , now apply BinarySearch in range [low-high];
*/


#include<bits/stdc++.h>
using namespace std;
void binary_search(int a[],int low,int high)
{
   //we already know binary search
}
int main()
{
    int a[10000000]; //infinite array.  (sorted)
    int low=0; int high=1; //let initially high=1;
    int key;
    while(key>a[high])
    {
        low=high;
        high=2*high;
    }
    //Now key<a[high]   hence now key is lie b/w index=low and high.
    //Now appplying binary search in range [low-high];
    binary_search(a,low,high);
    return 0;
}