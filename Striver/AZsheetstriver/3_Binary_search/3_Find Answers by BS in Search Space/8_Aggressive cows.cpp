#include <bits/stdc++.h>
using namespace std;


/*
    This is a C++ program that uses a binary search algorithm to find the largest minimum distance 
    between cows that can be placed on a set of stalls. The stalls are represented by an array a of
    integers, and the number of cows to be placed is specified by the variable cows.

    The program starts by sorting the array a in ascending order. It then defines the variables low 
    and high to specify the range of possible minimum distances that the program will search through. 
    low is initialized to 1, and high is initialized to the difference between the last and first elements of a.

    The program then enters a loop that continues until low is less than or equal to high. In each iteration 
    of the loop, it calculates the midpoint between low and high and stores it in the variable mid. It then 
    calls the function isPossible() with the array a, the number of elements in a (n), the number of cows (cows),
     and the current value of mid.

    The function isPossible() iterates through the elements of the array and tries to place cows at each element,
    keeping track of the number of cows placed and the last stall that a cow was placed at. If the distance 
    between the current element and the last placed cow is greater than or equal to the minimum distance, 
    the function increments the count of cows placed and updates the last placed cow to be the current element.
    When all the elements have been processed, the function returns true if the count of cows placed is greater 
    than or equal to cows, and false otherwise.

    If isPossible() returns true, the program updates low to be mid + 1 and continues the outer loop. If 
    isPossible() returns false, the program updates high to be mid - 1 and continues the outer loop.

    Finally, when the loop ends, the program prints the value of high, which is the largest minimum distance 
    between cows that can be placed on the set of stalls.
*/
bool isPossible(int a[], int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
}
   
int main() {
      int n = 5, cows = 3;
      int a[]={1,2,8,4,9};
      sort(a, a + n);

      int low = 1, high = a[n - 1] - a[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(a, n, cows, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      cout << "The largest minimum distance is " << high << endl;

      return 0;
}