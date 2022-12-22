#include<bits/stdc++.h>
using namespace std;

//sort an array using recursion

void insert(vector<int> &a,int value) //by reference is imp                (inserts element at correct position in a sorted array so that final array we get after adding value in array is also sorted)
{
      if(a.size()==0||a[a.size()-1]<=value)
       {
           a.push_back(value);
           return;
       }

      int zz=a[a.size()-1];
      a.pop_back();
      insert(a,value);
      a.push_back(zz);
}
void sort(vector<int> &a) //by reference is imp
{
    if(a.size()==1)
    return;
    int temp=a[a.size()-1];
    a.pop_back();
    sort(a);  //smaller input as we have popped out last element

    //now we need to place temp at correct position in this sorted array
    // this we can do using loop but here we will do this thing via recursion only.
    insert(a,temp);
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(14);
    a.push_back(10);
    a.push_back(6);
    a.push_back(5);
    a.push_back(0);
    a.push_back(12);
   sort(a);
   for(int i=0;i<a.size();i++)
   {
       cout<<a[i]<<" ";
   }

   return 0;

}
