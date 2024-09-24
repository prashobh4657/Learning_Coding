#include <bits/stdc++.h>
using namespace std;
int search(int a[], int n, int key)
{
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
    int a[] = {45, 33, 29, 14, 15};
    cout << search(a, sizeof(a) / sizeof(a[0]), 29);
    return 0;
}
/* Given an array in descending order (reverse sorted)  and key to search*/
// Return its index on which it is present
