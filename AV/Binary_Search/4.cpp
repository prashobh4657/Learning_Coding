#include <bits/stdc++.h>
using namespace std;

int search(int a[], int n, int key)
{
    if (n == 1)
    {
        if (a[0] == key)
            return 0;
    }
    else if (a[0] < a[1])
        asending_binary_search(a, n, key); // Refer 2.cpp
    else
        descending_binary_serach(a, n, key); // Refer 3.cpp
}
int main()
{
    int arr[] = {10, 23, 45, 66};
    cout << search(arr, 4, 23);
    return 0;
}

/* Order agnostic search */
/*
Given an array (sorted).
It may be sorted in ascending or descending.
*/
