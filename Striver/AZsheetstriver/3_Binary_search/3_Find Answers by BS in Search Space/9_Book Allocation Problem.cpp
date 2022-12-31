#include<bits/stdc++.h>
using namespace std;


/*
    This is a C++ function that uses a binary search algorithm to find the minimum number of pages that a 
    student must be assigned in order to distribute a given set of books among a specified number of students. 
    The books are represented by a vector of integers A, and the number of students is specified by the variable B.

    The function begins by checking if the number of students (B) is greater than the number of books 
    (the size of A). If it is, the function returns -1, since it is not possible to distribute the books 
    among more students than there are books.

    Next, the function defines the variables low and high, which will be used to specify the range of possible 
    number of pages that each student can be assigned. low is initialized to the minimum value in A, and high is
    initialized to the sum of all the values in A.

    The function then enters a loop that continues until low is less than or equal to high. In each iteration of 
    the loop, it calculates the midpoint between low and high and stores it in the variable mid. It then calls the
    function isPossible() with the vector A, the current value of mid, and the number of students (B).

    The function isPossible() iterates through the elements of the vector and tries to allocate them to students, 
    keeping track of the number of students and the total number of pages allocated to each student. If the total 
    number of pages allocated to a student exceeds mid, the function increments the count of students and resets 
    the total number of pages allocated to that student to be the current element. If the total number of pages 
    allocated to a student is already greater than mid, the function returns false. When all the elements have 
    been processed, the function returns true if the count of students is less than B, and false otherwise.

    If isPossible() returns true, the function updates high to be mid - 1 and continues the outer loop. 
    If isPossible() returns false, the function updates low to be mid + 1 and continues the outer loop.

    Finally, when the loop ends, the function returns low, which is the minimum number of pages that each 
    student must be assigned in order to distribute the books among the specified number of students.
*/

//to check if allocation of books among given students is possible.
int isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}
int books(vector < int > & A, int B) {
  if (B > A.size()) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i < A.size(); i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }
  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, B)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}
int main() {
  vector<int> A = {12,34,67,90};
  int B = 2;
  cout << "Minimum Possible Number is " << books(A, B);
  return 0;
}