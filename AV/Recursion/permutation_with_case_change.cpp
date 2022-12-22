/* i did this question without seeing video fully , only i see a glimpse of video to understand actual question and i did it 100%correct*/
//now i have seen video and verified that whatever did is correct by me
  
#include<bits/stdc++.h>
using namespace std;
void solve(string ip, string op)
{
    if(ip.length()==0)
    {
         cout<<op<<endl;
          return;
    }
    string op1=op;
    string op2=op;

    op1.push_back(ip[0]);
    op2.push_back(ip[0]-32); //alter  op2.push_back(toupper(ip[0]));

    ip.erase(ip.begin()+0);
    
    solve(ip,op1);
    solve(ip,op2);
}
void solve1(string s)
{
    string ip=s;
    string op="";
    solve(s,op);
}
int main()
{   string s;
      cin>>s;
    solve1(s);
    return 0;
}