/* Given a rotated sorted array. Tell number of times it is rotated.

let given array is
 2 5 6 8 11 12 15 18.......arr1
 after 4 times
 11 12 15 18 2 5 6 8..........arr2



now in question we are given only arr2
clearly observation in sorted array (arr1) minimum element is present at index 0 while in rotated sorted array (arr2) minimum element
is present at index 4
hence no. of times of rotation = index of minimum element in given rotated sorted array (arr2);


now we need to find index of minimum element
(can be find using linear search (first we can find minimum of array then its index using linear search) but we want use binary serach )


let us called 2 as pivot in arr2 (because 2 is minimum element)

we need,
    1. at once we get to know where arr[mid] == minimum element is or not
    2. something factor by which we can decide in which half we need to move further whether left half or right half;

    we have  11 12 15 18 2 5 6 8..........arr2
    here how can we say that 2 hi minimum h or koi nhi h
     here minimum element has a special feature i.e. it is smaller than both neighbours

    now in which direction we should move
    11 12 15 18 2 5 6 8..........arr2
    now we start at 11
            end at 8;
            now mid = (start + end )/2= (0+7)/2 = index 3 (middle)= mid 18

          11 12 15 18 left half with mid included           .......arr3
          18 2 5 6 8 right half with mid included          ........arr4
         z1. clearly here arr3 is sorted fully and arr4 not
         z2. also our minimum element is present in arr4 that is unsorted
          (he took another e.g and drawing to take out same observation as above hence aisa hamesha hota as mentioned in point z1 and z2)

         we need to find index of minimum element which is always present in unsorted half (may be right or left)
 */



// Here just read below :
/*  See this question :  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    and directly see this submission  : 03/15/2022 15:50	Accepted


 Some important points regarding this problem:
1. This is question clearly mention that array has distinct elements only.
2.  int next =(mid+1)%n;      // basically next neighbour hoga toh hamesha mid+1 hi but agar hum last element pr hue toh usse time
                                 pr hamara right neighbour hoga 1st element of array hence %n
    int prev=(mid+n-1)%n;     // basically previous neighbour hoga toh hamesha mid-1 hi but agar hum kabhi 1st element pr hue toh
                                 uska left elmeent will not exist and equivalently its left element would be last element of array
                                 hence add +N and then take %n hence net (mid-1 +n) %n
3.  if(nums[mid]<=nums[next]&&nums[mid]<=nums[prev])
    return nums[mid];
    //Here equality is important (Even if your array consists of distinct elements because there is a some moment when low=high
    so at that moment low and high pointing to same element hence this is important to pass some of testcases.

    if(nums[low]<=nums[mid])   //to determine which array half is unsorted, we will compare (low and mid) or (mid and high)
    low=mid+1;  //since a[low]<=a[mid] hence left half is sorted hence we will discard left half and further search in right half
    else      //else search in left half;
    high=mid-1;
    }

    if(nums[low]<nums[high]) //Considered array becomes sorted hence return first element;  (Imporntat condition not told by aditya verma)
    return nums[low];

    ==> Very important point : In sorted array that algorithm not works hence as soon as nums[low]<nums[high] (sorted) return nums[low];
        That's why nums[0]<nums[n-1] is checked before entering into while loop;
        Hence that's why if(nums[low]<nums[high])return nums[low] is there so that if array is sorted then just return nums[low];
        No need to execute while loop again.

      Let's verify this important point :  
      a[]=1 2 3 4 5
      Here mid = (0+4)/2 = 2;
      Here, left half with mid included and right half with mid included both are sorted.
      Hence that algorithm fails as it required one half should be unsorted.

    
    See this question : https://practice.geeksforgeeks.org/problems/rotation4723/1/# 
     ==> See this submission : 2021-07-21 07:41:16	Correct  (Minimum element found using linear search)

     ==> See this submission : 2022-03-15 16:15:55	Correct  (Minimum element found using binary search)
         --> Important points regarding this submission
              ->Full leetcode function is copy pasted in count function
              ->Do these 3 changes in return statements: 
                    1. return nums[0] ==> 0
                    2. return nums[mid]==>return mid
                    3. return nums[low]==>return low
                Because in gfg question index of minimum elements is asked while in leetcode question minimum elements is asked.
*/

/*
==> This problem has lot of glitches (also the exact code which aditya verma told also not getting submit on gfg and leetcode also
    hence just follow above points).
    Hence don't worry much about it.

*/