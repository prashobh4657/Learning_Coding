#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
vector<pair<int, int>> NGL(vector<int> arr, int n)
{
    vector<pair<int, int>> v;
    stack<pair<int, int>> st; // (NGL value , index of that NGL value)
    for (int i = 0; i <= n - 1; i++)
    {
        if (st.empty())
            v.push_back({-1, -1});
        else if (st.top().first > arr[i])
            v.push_back({st.top().first, st.top().second});
        else if (st.top().first <= arr[i])
        {
            while (st.size() > 0 && st.top().first <= arr[i])
                st.pop();

            if (st.size() == 0)
                v.push_back({-1, -1});
            else
                v.push_back({st.top().first, st.top().second});
        }
        st.push({arr[i], i});
    }
    return v;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    vector<pair<int, int>> ngl = NGL(price, price.size());

    vector<int> result;
    for (int i = 0; i < n; i++)
        result.push_back(abs(ngl[i].second - i));
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    return 0;
}
// Read problem : https://www.geeksforgeeks.org/the-stock-span-problem/  (Understand input and output using example manually;
/*
 ==> At any i, no. of consecutive elements smaller or equal to a[i] (including a[i]);
 ==> Manually at a given i, we are keep going back until we found a larger element than a[i];
hence NGL
(its brute force is   for(i=0;i<n;i++)for(j=i;j>=0;j--)similar to NGL);
*/

// Here to count the number of elements b/w a[i] and its NGL, we require NGL index (then no. of elements = i- ngl_index)
// hence just store its index also with NGL value  Hence pair is used.

/*
Let say i=3, and its NGL doesn't exist (means 4 elements are there which are smaller to it consecutively from i=0 to i=3)
means v[i]={-1,-1} ==> first value means NGL not exist , second value means take its NGL index as -1
so that when you do this  ngl[i].second-i  = 3-(-1) = 4 (which is same as expected)
Hence if there is value for which NGL doesn't exist then just give its NGL index -1
so that later you no need to check whether it's ngl exist or not. irrespective of its existence (it will give correct no. of consecutive elements);
*/
