#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st,int z)
{
    if(st.size()==0||st.top()<=z)
    {
        st.push(z);
        return;
    }

    int temp=st.top();
    st.pop();
    insert(st,z);
    st.push(temp);
    return;
}  
void sort(stack <int> &st)
{

   // if(st.empty()==true)
   if(st.size()==0)
    return;
    int val=st.top();
    st.pop();
    sort(st);
    insert(st,val);
    return;
}
int main()
{
    stack <int> st;
    st.push(4);
    st.push(5);
    st.push(45);
    st.push(0);
    st.push(2);

 /*   while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl; */


     sort(st);

      while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}