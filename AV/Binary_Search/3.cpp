#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &a, int key)
{
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key;
    cin >> key;
    cout << search(a, key);
    return 0;
}
/* Given an array in descending order (reverse sorted)  and key to search*/
// Return its index on which it is present
