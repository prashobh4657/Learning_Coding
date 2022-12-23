#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve(int idx, string curr, string &s, vector<string> &v)
{
    if (idx == s.size())
    {
        v.push_back(curr);
        return;
    }
    curr.push_back(tolower(s[idx]));
    solve(idx + 1, curr, s, v); // Take lower-case;
    curr.pop_back();            // backtrack;
    curr.push_back(toupper(s[idx]));
    solve(idx + 1, curr, s, v); // Take upper-case;
}
int32_t main()
{
    fio;
    string s;
    cin >> s;
    vector<string> v;
    string curr;
    solve(0, curr, s, v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}
