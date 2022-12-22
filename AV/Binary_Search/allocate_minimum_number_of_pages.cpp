#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* I submitted same code on gfg also , on doing suitable changes like (vector --> array and their variable terminology) but almost same code is submitted.  
 you can see proof as latest submission of this : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1 
 You study from below code only. 
*/
bool isvalid(vector<int> v, int n, int k, int mx)
{
    if (n < k)
        return -1; // v.imp for some test cases. (if n is no. of books, k=no. Of students)
    /* here no. of books < no. of students (this means there will at least one student which will not have any book),
    but in question it is written that each student must get at least one book hence that condition got violated in this condition
    hence return -1; */

    int students = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum > mx)  //as soon as sum>mx , we will create a new student and now start allocating book to him;
        {
            students++;
            sum = v[i];
        }
        if (students > k)  //if at any instant no.ofstudents required > k then return false;
            return false;
    }
    if (students > k)
        return false;
    else
        return true;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    int res = -1; //-1 in case if it is not possible;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isvalid(a, n, k, mid) == true)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << res << endl;
    return 0;
}

/*
Just see https://www.geeksforgeeks.org/allocate-minimum-number-pages/

Every book should be allocated.
Each book should be allocated to a single student only. (Two students can’t read same book).
There is a condition of continuity which is important.
Number of partitions = number of students.
We don’t want to put stress on any student. Hence maximum no. of pages (whosoever is allocated) should be minimized.

Here an array of pages of books may be sorted or may not be sorted. Hence we will apply binary search.

Let example :
10 20 30 40     m=2
Now possible partitions
[10] [20 30 40]    = [10][90] (here one student is allocated 10 pages and other 90) (max=90)
[10 20] [30 40]    = [30][70]  (here maximum pages allocated = 70)
[10 20 30] [40]    = [60][40]   (here maximum pages allocated = 60)

Clearly among all possibilities 3rd possibility has a minimum number of maximum-pages allocated to any student.

Here we want answer = 60;
Hence on binary_search_line on which our answer lies is maximum_number_of_pages.
Range of this line = [ 0 to (sum of all pages) ]
(because minimum pages which a student can read is 0 and maximum pages which a student can read is all pages);

Somewhat improvement : (Using giving conditions) Also, this line range can be somewhat reduced because of the condition
that each student must read at least one book.
Hence range = [ (maximum of array)  to (sum_of_all_pages) ];
Here maximum of array is because it is the minimum no. of maximum_pages which student has to read in any given scheme.
Because allocation is contiguous. All books will be distributed in a given scheme. Hence for best case
(maximum no. of pages is minimised), Let book having maximum no. of pages is given alone to any student
(means that student is given only book having maximum no. of pages).
Let this range be 0 to sum;
We will apply binary search on this line;

Here low=0 and sum=100 (in example 10 20 30 40)
Now mid = 50 (hence here now we have decided that any student will read atmost mid pages (50 pages))
Hence let’s start allocation
10 20 30 40
Here S1  = [10 (still can read 40 pages more)(50-10)  ⇒ [10 20 (still can read 20 pages more (50-(10+20)) ⇒ But next book is of 30 pages hence stop
S1 = [10 20;
Now let’s S2
S2= [30  (still s2 can read 20 pages more but next book is of 40 pages hence stop)
Now we are left with one more book , that book has 40 pages <50 hence we require one more student for that (but in question only two student are given)
S3 = [40  (virtual student)
Hence   S1=[10 20  , S2=[30 , S3=[40
Hence for at most 50 pages we at least required 3 students.
But here we have only 2 students hence this scheme is rejected. (Mid = 50 is rejected).
Now we want all pages to accommodate within these two students.
Hence we need to increase this capacity of atmost pages wali (then only we don’t require that 3rd student).
Hence we will increase mid. (hence we will go to the right half on the binary search line).

Hence
Now low=mid; (you can do low=mid+1 as well)
Now low=50 and high=100   ⇒ new mid = 75;
Means now one student can read at-most 75 pages
Now ,
10 20 30 40
Now
S1=[10 20 30 (still can read 75-(10+20+30) = 75-60=15pages but next book is of 40 pages hence stop)
S2 = [40
Done.      Hence S1=[10,20,30      S2=[40
Hence 75 is a candidate for our answer. Now we will search in the left half for a more minimized answer.

Now high=mid;
Now low=50 , high=75,     new mid=(50+75)/2 = 125/2=62;
Now check for 62;
This is also valid
Still search in left half;
New mid = 56; (then go to right half);
Finally answer is 60;


*/