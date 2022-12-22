/* leetcode problem level: medium
just type on google kth symbol in grammar and read question statemenet from leetcode website;

*/
/* we always when at n,k then we think        for some input small       
 then we think what to in  previous step to make our answer complete for this current step  */
// here the way in which are making input small is most imp;  n--->n-1 and          k can't be k---->k-1 as k-1 may or may not exist;
 //hence wisely make k small  and also we want what to some changes in previous (smaller input) to make our answer complete for current input

#include<bits/stdc++.h>
using namespace std;
int solve (int n,int k)
{
    if(n==1&&k==1)   //given in question
    return 0;

    int mid=(pow(2,n-1))/2;
       
       /*   0
            0 1
            0 1 1 0
            0 1 1 0 1 0 0 1
               obeservation skills
               for any row n, the column are same (from j=1 to mid)upto mid as that of n-1 row
               and for any row n the column after mid are just complement as that of previous row; */

    int p;
    if(k<=mid)
    p=solve(n-1,k);
    else
    p=1-solve(n-1,k-mid);  //subtract from 1 to make it complement;
    return p;
}
int main()
{
    int n,k;
    cin>>n>>k;
    //n is number of rows and k is value at row=n and column=k(1-based)
    int z=solve(n,k);
    cout<<z<<endl;
    return 0;
}
