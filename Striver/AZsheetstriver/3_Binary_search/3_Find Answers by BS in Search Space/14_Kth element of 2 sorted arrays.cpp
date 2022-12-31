#include<bits/stdc++.h>
using namespace std;

/*
        This is a C function that finds the kth element in the sorted merge of two given arrays, 
        arr1 and arr2, of sizes m and n, respectively. It uses a binary search algorithm to determine
        which elements of the arrays to compare in each iteration.

        The function begins by checking if m is greater than n, and if it is, it calls itself with arr2
        and arr1 as the first two arguments and n and m as the third and fourth arguments, respectively. 
        This ensures that the binary search is always performed on the smaller of the two arrays.

        The function then defines the variables low and high to represent the left and right bounds of 
        the search range, respectively. It initializes low to the maximum of 0 and k minus m, and high 
        to the minimum of k and n. This ensures that the search range is within the bounds of both arrays.

        The function then enters a loop that continues until low is less than or equal to high. In each 
        iteration of the loop, it calculates the midpoint between low and high and stores it in the variable
        cut1. It then calculates cut2 to be k minus cut1.

        The function then defines the variables l1, l2, r1, and r2 to represent the elements just before
        and just after the cuts in both arrays. If the cuts fall at the beginning or end of an array, the 
        corresponding variable is initialized to either the minimum or maximum value of an int type.

        The function then checks if both l1 is less than or equal to r2 and l2 is less than or equal to r1. 
        If both conditions are true, the function returns the maximum of l1 and l2, as this is the kth element
        in the sorted merge of the two arrays.

        If either condition is false, the function updates either low or high and continues the loop. If l1
        is greater than r2, high is updated to be cut1 minus 1. If l2 is greater than r1, low is updated to 
        be cut1 plus 1.

        Finally, if the loop ends without returning a value, the function returns 1.


*/
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}
int main() {
    int array1[] = {2,3,6,7,9};
    int array2[] = {1,4,8,10};
    int m = sizeof(array1)/sizeof(array1[0]);
    int n = sizeof(array2)/sizeof(array2[0]);
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "
    <<kthelement(array1,array2,m,n,k);
    return 0;
}