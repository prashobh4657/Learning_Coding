/* 
 Given an sorted rotated array.(A sorted array is rotated).
  Number of rotations -> index of minimum element
  To find index of minimum element see this file "7_number_of_times_a_sorted_array_is_rotated.cpp"

  Observation : 
  This rotated sorted array is sorted from index=
  1. min_element_index to n-1
  2. 0 to min_element_index-1

 //let min_element_index= idx;
  So apply Binary search in these sorted halfs
    1. BS(arr,0,idx-1,target)   = let this return a
    2. BS(arr,idx,size-1,target) =let this return b 
    (assume if element is not found BS() function return -1)
    if(a>=0 || b>=0)
    {
        if(a>=0)
        return a;
        else
        return b;
    }
    else    //means a=-1,b=-1 (both a,b<0)
    return -1; // key is not present in rotated sorted array (given array)
*/
/*
Question : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 
     ==> See submission : 03/17/2022 22:09	Accepted 
Some important points regarding submission : 
  1. count() function is taken from reference given in file "7_number_of_times_a_sorted_array_is_rotated.cpp"  (GFG submission)
     ==>In particular : GFG Question : https://practice.geeksforgeeks.org/problems/rotation4723/1/# 
        =>See this submission : 2022-03-15 16:15:55	Correct  (Minimum element found using binary search)
  2. BS() function is binary search function
  3. search() function is based on concept which is discussed in this file above.
*/

/*
Alternate approach (thought by myself) (but in this approah confusion is that whether to left rotate or right rotate);
    We know, index of minimum element= number of rotations;
    1.find index of minimum element , let it be i
    2. now rotate this array i times
    3. Now this array is sorted , now apply binary search
*/
