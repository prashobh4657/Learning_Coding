#include<bits/stdc++.h>
using namespace std;


set <string> st;

void solve(string ip,string op)
{
     if(ip.length()==0)
     {
         st.insert(op); //here instead of output the op we are just inserting it into set which we will remove duplicacy
        // cout<<op<<endl;
         return;
     }
     string op1;
     string op2;

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

    set<string> :: iterator it;
    for(it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<endl;
    }


    return 0;
}