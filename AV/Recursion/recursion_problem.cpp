#include<bits/stdc++.h>
using namespace std;
void print_increase(int n)  // print 1 to n;
{
    if(n==1)
    {
        cout<<1<<endl;
        return; //even this function has return type void then also return statement is necessary 
                // alter way to avoid writing return statement is put all other statements other than base condition statements in else part

    }
    print_increase(n-1);
    cout<<n<<endl;
}
void print_decrease(int n) //print n to 1;
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<endl;
    print_decrease(n-1);
}
int fact(int n)  // print factorial of n;
{
    if(n<0)
    {
        cout<<"factorial not defined";
        return n;
    } 
    if(n==0||n==1)
    return 1;

    return fact(n-1)*n;
}

string reverse(string s) // reverse a string
{
    if(s.length()==0)
    return "";


    return reverse(s.substr(1,s.length()-1))+ s[0];

}

int main()
{
    int z=5;
   print_increase(z);
   print_decrease(z);
    cout<<fact(z)<<endl; 

    string z1="How_Are_You?";
    cout<<reverse(z1);
    return 0;

}