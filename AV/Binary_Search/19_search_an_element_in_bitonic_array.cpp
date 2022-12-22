/* 
 Search in bitonic array;
  Given an bitonic array and key. Return index of key in bitonic array.
  
  Here we know bitonic array has two parts:
    1. increasing part.
    2. Decreasing part. 

    Clearly increasing part array will be sorted in ascending order.
    And decreasing part array will be sorted in descending order.
   (you can include peak element in any part, that ascending/descending sorted property of both parts will not be violated).
     And we know how to search element in sorted array (ascending or descending both).

    Hence now just we need to divide the array into these parts.
    Clearly this division will happen at peak element.
    Hence first find index of peak element (let k). (Video 18);
 
   (here you can include peak element in any part of array either increasing part or descreasing part  or in both).
   Now Binary search on BS(arr,0,k)   (including peak element in increasing part).      let return z1;
  Then apply binary search (descending sorted) BS(arr,k+1,n-1)                        let return z2;

   if(z1==-1&&z2==-1)
   return -1; //means in overall array element is not exist;
   else if(z1>0)
   return z1;
   else
   return z2;
*/
/*
Somewhat similar to searching in rotated sorted array.
 Rotated sorted array is not equal to bitonic array (we know).
 In rotated sorted array , we find minimum element index , and divide into two across that element and then apply BS in both halves.

*/