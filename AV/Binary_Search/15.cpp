/* 
  Minimum difference element in a sorted array; (This question is v. interesting becuase answer of this question
  We have already written as answer of some other question, but it is difficult to strike that thing, that this question is 
  similar to that question);

Given array and key. Now find an element (a[i]) in array for which abs(a[i]-key) is minimum.
 --> What if key is present, then ans=0;
 --> What if key is not present, then ans=min(key-floor(key),ceil(key)-key);
      

      My approach :      let a[] be array;
                     z=BS(a,0,n);  //apply binary search;
                       if(z>0)   //means present in array;
                       {
                           return 0;   //in that case minimum difference=0;
                       }
                       else if(z==-1)  //key not exist in array;
                       {
                           return min(abs(key-floor(a,n,key),abs(ceil(a,n,key)-key)));   
                       }
                        //see these floor,ceil functions (already discussed in previous videos);
                        // (Topic : ceil/floor of an element in sorted array);


Also one more observation, 
Aditya verma:  (he told this solution) (because of this observation code get shortened) 
Do binary search, (if key is not in array), then at the end of binary search ,
 high point to = floor of key;  low point to = ceil of key;
 Hence finally do min(key-a[high],a[low]-key);

*/
