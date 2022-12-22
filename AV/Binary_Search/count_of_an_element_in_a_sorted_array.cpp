/* count of an element in a sorted array

 just concept is count =  (index of last occureence of key  - index of first occurence of key) + 1;   */
/* for input
8
2 4 10 10 10 18 20 20
10
output should be 3  */

#include <bits/stdc++.h>
using namespace std;

int first_occurence(int a[], int n, int key) // first occurrence
{

    int low = 0;
    int high = n - 1;
    int res = -1; // if not found then return -1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (a[mid] == key)
        {
            res = mid;      // store this occurence in result variable;
            high = mid - 1; // keep searching in left half;
        }
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int last_occurence(int a[], int n, int key) // first occurrence
{

    int low = 0;
    int high = n - 1;
    int res = -1; // if not found then return -1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (a[mid] == key)
        {
            res = mid;     // store this occurence in result variable;
            low = mid + 1; // keep searching in right half;
        }
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int count(int a[], int n, int key)
{
    if (first_occurence(a, n, key) == -1) // alter you can write last_occurence(a,n,key)==-1
        return 0;

    return (last_occurence(a, n, key) - first_occurence(a, n, key)) + 1;
}
int main()
{
    int n;
    cin >> n;
    int i;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << count(a, n, key);
    return 0;
}