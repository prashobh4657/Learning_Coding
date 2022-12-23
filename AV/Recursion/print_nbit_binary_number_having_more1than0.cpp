//GFG Link : https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article 
/*Just see latest submission;
  ==>op=curr
  ==>op1 and op2 because so that no need to backtrack hence using extra variables;
  ==>one,zero represent no. of 1's and 0's used till now and n represent no. of remaining characters; 
  ==>If(one>zero) means 2 choices : either this bit can be 0 or 1;
     else only have to use 1 (if 0 used then in this prefix no. of 0 will be > no. of 1);
 */
