#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<int> NGR(vector<int> arr, int n) // Nearest Greater to Right
{
    vector<int> v;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            v.push_back(-1);
        else if (st.top() > arr[i]) // Since st is not empty hence we can access top(), (If it would be empty then above if will get execute);
            v.push_back(st.top());
        else if (st.top() <= arr[i])
        {
            while (st.size() > 0 && st.top() <= arr[i]) // Pop untill stack becomes (empty or s.top()>a[i]);    Keep popping untill st.top()<=arr[i];
                st.pop();                               // The elements which are getting popped can't be answer further because for element from index 0 to i
                                                        // the nearest greater element for them will be arr[i] itself (see last line of loop, we are pushing arr[i] on stack)
                                                        // as (we are popping those elements which are st.top()<=arr[i]);

            // Above while-loop can terminate because of two-conditions, hence if-else;
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
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ngr = NGR(a, n);
    for (int i = 0; i < n; i++)
        cout << ngr[i] << " ";

    return 0;
}
