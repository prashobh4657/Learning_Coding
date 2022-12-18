
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
vector<int> NSR(vector<int> arr, int n)
{
    vector<int> v;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            v.push_back(-1);
        else if (st.top() < arr[i])
            v.push_back(st.top());
        else if (st.top() >= arr[i])
        {
            while (st.size() > 0 && st.top() >= arr[i])
                st.pop();

            if (st.size() == 0)
                v.push_back(-1);
            else
                v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> nsr = NSR(a, n);
    for (int i = 0; i < n; i++)
        cout << nsr[i] << " ";

    return 0;
}

// Same as NGR (Only change > --> < and < --> >)
