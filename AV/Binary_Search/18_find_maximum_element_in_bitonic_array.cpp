/*
  Bitonic array --> Find maximum element of array;

  To find maximum element in array : Time complexity O(n).

  But using bitonic property this complexity will reduce.
  Bitonic property: Monotnoically increasing and then monotonically decreasing.
    Means  for first part of array a[i]<a[i+1] (strictly)
     and for 2nd part of array a[i+1]<a[i]  (strictly)

     Array values will increase smoothly and then drecrease smoothly.
    --> Maximum element will be on peak.
    --> We have already solved question : find peak element.
    --> Here in this question , there will be only one peak element for sure.

    Hence maximum element in bitonic array == find peak element in array, O(logn) complexity.
*/
