/* for example you are given a string 
     ABCD
then you have to print all possible combination with spaces in the same order of string  (don't permute characters of string)
 b/w each character there can be space or no space hence this will make possible combinations
first character will be as it is A 
now space can be there or not A_   , A   ...now add B in each of these two A_B  , AB 
now again two choices add C with space or withou space     ,  now aging two choices add D with spaces or without spaces 
 hence total combination are 
a b c d
a b cd
a bc d
a bcd
ab c d
ab cd
abc d
abcd */

#include<bits/stdc++.h>
using namespace std;
void solve(string ip , string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }
    string op1=op;
    string op2=op;

     
    op1.push_back(' ');    // with space;
    op1.push_back(ip[0]);

    op2.push_back(ip[0]); //without space;

    ip.erase(ip.begin()+0); //made input smaller;

    solve(ip,op1);
    solve(ip,op2);
    return;
}
void solve1(string s)
{    
    string ip=s;  //imp line  (initially i am forgetting this line)
    string op;

    op=ip[0];   //first charater toh lena hi h;
    ip.erase(ip.begin()+0);
    solve(ip,op);

}
int main()
{   
    string s;
    cin>>s;
    solve1(s);
    return 0;
}