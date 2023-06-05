#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Here modifiying NSR , NSL as  ==> v and stack <int> ==>  pair<int,int> that is corresponding nsr,nsl value --> corresponding index
// To prevent checking : NGR/NSR exist or not we can give proper corresponding index so that we can get correct answer;
// In case NSL or NGL : If for any a[i] it's NGL or NSL is -1 then take its corresponding index also -1;
// In case NGR or NSR : If for any a[i] it's NGR or NSR is -1 then take its corresponding index as n;
vector<pair<int, int>> NSR(vector<int> &arr, int n)
{
    vector<pair<int, int>> v;
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            v.push_back({-1, n});
        else if (st.top().first < arr[i])
            v.push_back({st.top().first, st.top().second});
        else if (st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();

            if (st.size() == 0)
                v.push_back({-1, n});
            else
                v.push_back({st.top().first, st.top().second});
        }
        st.push({arr[i], i});
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<pair<int, int>> NSL(vector<int> &arr, int n)
{
    vector<pair<int, int>> v;
    stack<pair<int, int>> st;
    for (int i = 0; i <= n - 1; i++)
    {
        if (st.empty())
            v.push_back({-1, -1});
        else if (st.top().first < arr[i])
            v.push_back({st.top().first, st.top().second});
        else if (st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
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
int MAH(vector<int> &a)
{
    vector<pair<int, int>> nsr = NSR(a, a.size());
    vector<pair<int, int>> nsl = NSL(a, a.size());

    vector<int> area(a.size());
    for (int i = 0; i < a.size(); i++)
        area[i] = abs(nsr[i].second - nsl[i].second - 1) * a[i];

    return *max_element(area.begin(), area.end());
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    cout << MAH(a);

    return 0;
}
