/* Determine first occurence of a element in sorted array return its index .
   For e.g. 2 4 10 10 10 18 20, key=10, ans =2; */

#include <bits/stdc++.h>
using namespace std;
int first_occurrence(vector<int> a, int key)
{
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (a[mid] == key)
        {
            if (mid == 0 || ((mid - 1 >= 0) && a[mid] > a[mid - 1])) // It is really its first occurence
                return mid;
            else
                high = mid - 1; // Keep searching in left half of array;
        }
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int last_occurrence(vector<int> a, int key)
{
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (a[mid] == key)
        {
            if (mid == n - 1 || ((mid + 1 < n) && a[mid] < a[mid + 1]))
                return mid;
            else
                low = mid + 1;
        }
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
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
    cout << first_occurrence(a, key) << endl;
    cout << last_occurrence(a, key) << endl;
    return 0;
}
/*
My solution : See function first_occurrence(),last_occurrence();
    ==> I thought by myself completely this code.
    ==> Just see code : Here like accessing mid-1 and mid+1 etc. hence need to apply conditions like is mid-1>=0 and mid+1<=n-1 and also
        also for mid==0 (in first_occurrence) and for mid==n-1 (last_occurrence) need to write separate condition
    ==> I submitted these functions on Coding ninja submission.
Coding ninja link : https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?leftPanelTab=0
==> Just see latest submission ==> Submitted first_occurrence(),last_occurrence();
==> Don't follow these codes as in these writing conditions is imp. and recalling them is bit difficult.
    Hence follow AV code. AV code is submitted on GFG and leetcode.

AV Solution : For that Just see "Searching_Sorting1.cpp" in "FINAL 450";
*/
