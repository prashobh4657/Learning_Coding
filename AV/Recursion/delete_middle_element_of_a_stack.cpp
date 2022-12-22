#include<bits/stdc++.h>
using namespace std;

//if size even then  size/2 from top           [1,2,3,4    ==> (4 is top)====> 3 should delete
//if size odd then (size)/2 + 1 from top       [1,2,3,4,5  ==> (5 is top)====> 3 should delete

void delete_middle_element(stack <int> &st,int size)
{

    int k= (size/2)+1;
    if(k==0)
    return;

     if(k==1)
     {
         st.pop();
         return;
     }
     int val=st.top();
     st.pop();
     delete_middle_element(st,k-1);
     st.push(val);
     return;

}
int main()
{

    stack <int> st;
    st.push(10);
    st.push(150);
    st.push(120);
    st.push(101);
    st.push(44);
    //st.push(0);
    delete_middle_element(st,st.size());

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;
}