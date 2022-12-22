#include<bits/stdc++.h>
using namespace std;

char next_alphabet(char a[],int n,char key)
{
    int low=0; int high=n-1;
    char result='z'+1;  // 'z'+1 is equivalent to INT_MAX in character     (here 'z'+1 == { )  (means if answer not exist then ans={)
    while(low<=high)
    {
        int mid= low + (high-low)/2;
        if(a[mid]==key)
        low=mid+1;
        else if(a[mid]<key)
        {
            low=mid+1;
        }          //also here instead of if and else-if,  you can just club these two (in one if) as   "if(a[mid]<=key) low=mid+1;"
        else
        {
            result=min(result,a[mid]);
            high=mid-1;
        }
    }
    return result;
}
int main()
{
     char arr[]={'a','b','c','f','h'};
     char p='a';
     for(p='a';p<='i';p++)
     cout<<next_alphabet(arr,5,p)<<" ";
    
    return 0;
}


/*
Problem statment: 
  Given sorted array of alphabets.
  Given key (an alphabet).
  Find next character which is larger than key.
  E.g. =[a c f h]
        key=f
        Answer = h
Similar to ceil problem
Difference : 
           1. numbers vs alphabets.
           2. Here if f is exist (if your key is f) then also you have to give h (next character which is present in array) as output 



Code variation : 

*/