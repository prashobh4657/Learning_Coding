#include<bits/stdc++.h>
using namespace std;


void insert_at_bottom(stack <int> &st,int val)
{
    if(st.size()==0)
    {
        st.push(val);
        return;
    }
    int temp=st.top();  st.pop();
    insert_at_bottom(st,val);
    st.push(temp);
    return;
}
void reverse(stack <int> &st)
{
    if(st.size()==1)
    {
        return;
    }
    int z=st.top(); st.pop();
    reverse(st);
    insert_at_bottom(st,z);
    return;
}

void print(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}
int main()
{
    stack <int> st;
    st.push(5);
    st.push(7);
    st.push(-8);
    st.push(9);
    print(st);
    reverse(st); 
    print(st);
    return 0;
}