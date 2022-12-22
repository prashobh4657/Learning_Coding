#include<bits/stdc++.h>
using namespace std;

void solve(int one,int zero,int n,string op)
{
    if(n==0)
   {
       cout<<op<<" ";
       return;
   }
   if(one>zero)
   {
     string op1=op;
     string op2=op;
     op1.push_back('1');
     solve(one+1,zero,n-1,op1);

     op2.push_back('0');
     solve(one,zero+1,n-1,op2);

   }
   else
   {
      string op1=op;
      op1.push_back('1');
      solve(one+1,zero,n-1,op1);
   }

}
void solve1(int n)
{
    string op="";
    int one=0;
    int zero=0;
    solve(one,zero,n,op);
}
int main()
{
    int n;
    cin>>n;
    solve1(n);

    return 0;
}


/* 
 Print N digit Binary 1's >0's in all its prefixes
Flow
1: IP-OP
2. Correction: 
 in problem it should be 1's >= 0's (in gfg problem statement is written wrong)
3. recursive tree (using ip-op)
        we will have some 1's and some 0's
             int ones, int zeroes
            Here we have 3 boxes (each box has choice either fill by 0 or 1)

         int ones=0, int zeroes=0  (here their count will represent how much we have filled)
         Here finally n will become 0 and one=x and zeroes=y (x+y=n)
          
        Here op,ip
        here in starting we can't include 0 first 
        as if we take prefix of only that character then our string will "0" (will not be accepted)
        hence at first we must include 1
             |
      IP:(one=1,zeroes=0,n=n-1=3-1=2),OP="1"
             | 
           /   \  (now two choice , whether to take 0 or 1)
      take 1   take0 
    (one=2)       one=1,zero=1,n=1 (IP) 
   (zeroes=0)     "10" (OP)
    n=1
    "11"
      /\      
       see complete recursive tree in word document.


 here at each level we are decreasing n by 1.
  and increasing count of zero by 1 or one by 1.


  
   now we will observe it.
   Here choice for 1 is always available
   here choice for 0 is not always available
   now we need to write if condition for choice for 0
   here we can make choice of 0 only when we have used more 1's than 0's already included till now.
   hence condition is 1's>0's for choice of 0 at current step.

*/


/* 
  given n;
  n=5
  now we will print a binary string of length 5 (means having only 1 or 0)
  Now let say 11110 
  Now in all prefixes of this string 
  no. of 1's >= no. of 0's

  means 11110, 1111,111,11,1,{}(empty prefix) (here we will not consider empty prefix)
     (a number is prefix of itself and all other prefixes are known as proper prefixes)
     Here clearly in all of these prefixes 1's>0's hence 11110 is acceptable for n=5
     now list all binary strings of length 5 which are acceptable.

  let see 10101
  10101 (accepted), 1010 (accepted) , 101(accepted) , 10(accepted), 1 (accepted) here all accepted
  hence 10101 is accepted 
  



*/
/* his code: 
   if(n==0)
   {
       cout<<op<<" "; return;
   }
   string op1=op;
   op1.push_back('1');
   solve(one+1,zero,n-1,op1);
   if(one>zero)
   {
       string op2=op;
       op2.push_back('0');
       solve(one,zero+1,n-1,op2);
   }

 (but i think , mine is also correct which i wrote above (uncommenteed))
 becaue it is giving same answer for n=3 as tthat in recursive tree he explained.
*/

