#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(vector<int> v,int k,int index,int &ans)
{
    if(v.size()==1) //when only one input left then that is our answer;
    {
        ans=v[0]; return;
    }

    index=(index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index,ans);
}
int main()
{
    int n,k; cin>>n>>k;
    vector<int> a;
    for(int i=1;i<=n;i++)
    a.push_back(i);
    
    int answer;
    solve(a,k-1,0,answer);
    
    cout<<answer<<endl;
    return 0;
}


/*
 Josephus problem
 1. Story time
 2. IP-OP-PS
 3. Identy recursion?
 4. Explaination
 5. Code

 Story:  <not writing story>

 Input : n total people , k=no. of people to be skipped (in a round) and kill kth person.
 output : last person's original position which is left finally. (We have to final person position) (imp : that position should be that position which is intially alloted (when no-one was died))
 Example: n=40 k=7, Output: 24

 How recursion ? 
  --> Tree
  --> Choice + decision
  --> problem already recursively defined (e.g. kth grammar); (nth step depends on (n-1)th step);
 
 Solve using IBH: 
   1. a. Hypothesis --> n;
      b. Smaller ip
   2. Base condition;    : if n=0 (last person should be there) hence n=1 is valid input 
   3. Induction; : there is no induction step here (as the person which is killed will not be used further); (unlike in question sort array using recursion in which we remove last element and after getting answer of input n-1 , we put that removed element at correct position and that last element is useful hence there was a somewhat induction step). (but here there is no induction step). 

   Let's use array data structure, %;

   Dry run :n=5 1 2 3 4 5     and k=2
   (here 1st person count (including him also)) -->1 2 (k=2) hence 2nd person killed

   Now we will actually delete that element
   1 3 4 5
   Now 3 will count (including him) and kill after counting 2  ,  --> 3, 4
   Hence 4th person killed.
   1 3 5  
   Here we will actually make size small. (also here original position preserved).
   Now 5 will start counting.
   1 will be killed.
   Now we will use modulo.
   (i+k-1)%n  (we are actually adding k-1 each time) and later let's take %n to get exact position.
   THen 3 will start counting (k=2)  . 5th person killed.
   3rd person left;

  
  Here let's put k-1=z 
   Here will pass (k-1 itself from main)
   (i+z)%n



*/