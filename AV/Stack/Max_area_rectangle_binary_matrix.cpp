#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }

    // Somewhat like prefix-sum;
    vector<vector<int>> modify_matrix(n, vector<int>(m));
    modify_matrix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0)
                modify_matrix[i][j] = modify_matrix[i - 1][j] + v[i][j];
            else
                v[i][j] = 0;
        }
    }

    int answer = INT_MIN;
    for (int i = 0; i < n; i++)
        answer = max(answer, MAH(modify_matrix[i]));
    cout << answer;
    return 0;
}
/*
Difference b/w MAH & MAR

1. MAH (Maximum area histogram) : 1d array , positive numbers
2. MAR (Maximum area rectangle) : 2d array , only 0 and 1 (binary matrix)

Similarity
In both questions maximum area rectangle is required



Approach :
Given matrix
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

We will modify this matrix as :
Row 1 : 0 1 1 0 =H1
Row 2 : 1 2 2 1 =H2
Row 3 : 2 3 3 2 =H3
Row 4 : 3 4 0 0 =H4

General formula : rowx[i]!=0 then rowx[i]=row(x-1)[i]+a[row][i]  else rowx[i]=0;(because building can't be in air)  (Here x is row number);

Now Answer = max(MAH(H1),MAH(H2),MAH(H3),MAH(H4))
*/
