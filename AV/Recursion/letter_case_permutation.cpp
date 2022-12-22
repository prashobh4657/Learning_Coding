#include<bits/stdc++.h>
using namespace std;

//letter case Permutation
void solve(string ip,string op,vector <string> &v)
{
    if(ip.length()==0)
    {
        v.push_back(op);
        return;
    }
   
    char z=ip[0];
    ip.erase(ip.begin()+0);
    if(isdigit(z))
    {
        op.push_back(z);
        solve(ip,op,v);
    }
    else if(isalpha(z))
    {
         string op1,op2;
         op1=op2=op;
         op1.push_back(z);  //taking as it is;

        //in choice 2 (op2) taking its opposite (like if it is small then taking capital case else if it is captial then taking small case)
        if(islower(z))
        op2.push_back(toupper(z));
        else if(isupper(z))
        op2.push_back(tolower(z));

        solve(ip,op1,v);
        solve(ip,op2,v);
    }
    
}
vector <string> solve1(string s)
{
    string ip=s;
    string op="";
    vector<string> v;
    solve(ip,op,v);
    return v;
}

int main()
{
    string s;
    cin>>s;
    vector<string> a=solve1(s);
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";

    return 0;
}








/* 
 Input: 
   Given a string having lowercase/uppercase/digits.
   and now print all possible strings having changed case of letters
   IP: 
      a1B2
      a1b2
      A1B2
      A1b2
      here we have only two letters hence each have two choices either lower or capital hence total 4 possibilities
      digit will remain as it is.

       Recursive tree
          a1B2
    (now we are at a ) 
        /          \
     lower a        upper A (taking that character as it is and its opposite case = two choices)
 ip=1B2,op="a"   ip=1B2 op="A"
        |              |                     (here we will have only one child as next character is digit hence just include it in op and make ip small)
    ip="B2"          ip="B2"                 (in case of digit think yourself if you make 2 child then their will be duplicacy , you can make that recursive tree also and feel it (finally you will get lot of strings duplicate)) (hence this recursive tree is correct)
    op="a"+1="a1"        op="A"+1="A1"
      /\                /\       (next character is B)  
(next character ...........process  and so on)

*/

   