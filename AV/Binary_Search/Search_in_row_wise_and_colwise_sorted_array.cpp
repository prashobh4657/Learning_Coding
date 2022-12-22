#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int key;
    cin >> key;
  

    pair<int, int> answer(-1, -1);
    int i = 0;
    int j = m - 1;
    while (i < n && j > 0)
    {
        if (a[i][j] == key)
        {
            answer.first = i;
            answer.second = j;
            break;
        }
        else if (a[i][j] > key)
            j--;
        else
            i++;
    }
    cout << answer.first << " " << answer.second;
    return 0;
}

/* Let solve question 2d array which is sorted row wise and column wise;

 Brute force: search in matrix  O(n^2) complexity;
 Approach : We will traverse from top-right;
            i=0,j=m-1; (here this is our mid);
            We will move this pointer;
            in each case we have to  choice either to move down (i++)or left (j--);
            based on comparision of a[mid] and key;
      In worst case (key found in bottom left) : O(n+m) steps;


      When key is not found :
           then we will be still following correct path where that key could be.
           but at the last moment we tend to do j-- (when j=0) or i++(when i=n-1)
           hence we tend to go out of bound. (in that we will be need case return -1);

           As in each step, we keep moving left or bottom hence j>0 and i<n;
*/
