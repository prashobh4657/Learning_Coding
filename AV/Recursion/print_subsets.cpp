#include<bits/stdc++.h>
using namespace std;

/* if in this program we have a string having duplicate characters like  bbcc then its subsets will be printed 
as if there are four distinct characters  like b1 , b2, c1, c2 and hence its some subsets will printed more than once  
 to avoid this thing please another program */
void solve(string ip,string op)
{
     if(ip.length()==0)
     {
         cout<<op<<endl;
         return;
     }
     string op1;
     string op2;

// here op1 &op2 both =op (because we have to  op1 & op2 as op ) and now decide for next character(input ka 1st character) to take it or not
     op1=op;
     op2=op;
     
     op2.push_back(ip[0]);
       

    ip.erase(ip.begin()+0);

     //now ip has become smaller ip (basically ip has become smaller input)
     solve(ip,op1);
     solve(ip,op2);
}
int main()
{
    string s;
    cin>>s;
    string op=""; //empty string;
    solve(s,op);
    return 0;
}


/* if you want to pass string only from main() function i.e only one parameter then you can do this thing;  


void solve1(string ip,string op)
{
     if(ip.length()==0)
     {
         cout<<op<<endl;
         return;
     }
     string op1;
     string op2;

     op1=op;
     op2=op;
     op2.push_back(ip[0]);
       

    ip.erase(ip.begin()+0);
     

     //now ip has become smaller ip (basically ip has become smaller input)
     solve1(ip,op1);
     solve1(ip,op2);
}
void solve(string s)
{
    string op="";
    solve1(s,op);
}
int main()
{
    string s;
    cin>>s;
    solve(s);
    return 0;
}   */


