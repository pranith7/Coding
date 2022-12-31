#include<bits/stdc++.h>
using namespace std;


void merge(int ar1[], int ar2[], int n, int m) {
  // merge two sorted arrays with out extra space
  /*
      The function merge takes in two sorted arrays, ar1 and ar2, of lengths n and m, respectively, 
      and merges them without using any extra space.

      The function first initializes the variable gap to be the ceiling of the ratio of the sum 
      of the lengths of the two arrays over 2. It then enters a loop that continues until gap is 0. 
      Inside the loop, the function declares two variables i and j, both initially set to 0. i is the 
      index for ar1 and j is the index for ar2. The function then enters a nested loop that continues 
      until j is greater than or equal to n + m. Inside the nested loop, the function checks the following
      conditions in order:

      If j is less than n and the element at index i in ar1 is greater than the element at index j in 
      ar1, the function swaps these two elements.
      If j is greater than or equal to n and i is less than n and the element at index i in ar1 is 
      greater than the element at index j - n in ar2, the function swaps these two elements.
      If j is greater than or equal to n and i is greater than or equal to n and the element at
      index i - n in ar2 is greater than the element at index j - n in ar2, the function swaps these
      two elements.
      
      After all these checks, the function increments both i and j by 1.

      After the nested loop finishes, the function checks if gap is 1. If it is, it sets gap to 0. 
      Otherwise, it sets gap to the ceiling of the ratio of gap over 2.

      Once the outer loop finishes, the function has merged the two arrays ar1 and ar2 without 
      using any extra space.
  */
  int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && ar1[i] > ar1[j]) {
        swap(ar1[i], ar1[j]);
      } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
        swap(ar1[i], ar2[j - n]);
      } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
        swap(ar2[i - n], ar2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
}

int main() 
{
  int arr1[] = {1,4,7,8,10};
  int arr2[] = {2,3,9};
  cout << "Before merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;
  merge(arr1, arr2, 5, 3);
  cout << "After merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }

}