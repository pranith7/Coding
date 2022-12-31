//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int A[], int N){
    // Your code goes here
	/*
		The missingNumber function takes an array of integers A and an integer N as input, and returns the 
		missing number in the array A. The array is assumed to contain all the integers from 1 to N, 
		inclusive, except for one missing number.

		The function first initializes a variable ans to 0. This variable will be used to store the result 
		of the XOR operations performed on the elements of the array.

		The function then iterates through the elements of the array from index 0 to N-2, performing a bitwise XOR 
		operation on each element and the current value of ans. This has the effect of canceling out all the elements 
		of the array that appear an even number of times, leaving only the missing element.

		The function then performs a similar operation on all the integers from 1 to N, inclusive, performing a 
		bitwise XOR operation on each integer and the current value of ans. This has the effect of canceling out 
		all the integers from 1 to N that appear an even number of times, leaving only the missing integer.

		Finally, the function returns the value of ans, which is the missing integer in the array A.
	*/
    int ans=0;

    for(int i=0; i<N-1; i++)
        ans=ans^A[i];
		
    for (int i=1; i<=N;i++)
        ans=ans^i;
    return ans;
}
//   if N <= arr[i] <= M
int missingNumber(int A[], int N, int M) {
  int ans = 0;

  for (int i = 0; i < N - 1; i++) {
    ans = ans ^ A[i];
  }

  for (int i = N; i <= M; i++) {
    ans = ans ^ i;
  }

  return ans;
}

// vector < int >Solution::repeatedNumber (const vector < int >&arr) {
//     /* Will hold xor of all elements and numbers from 1 to n */
//     int xor1;

//     /* Will have only single set bit of xor1 */
//     int set_bit_no;

//     int i;
//     int x = 0; // missing
//     int y = 0; // repeated
//     int n = arr.size();

//     xor1 = arr[0];

//     /* Get the xor of all array elements */
//     for (i = 1; i < n; i++)
//         xor1 = xor1 ^ arr[i];

//     /* XOR the previous result with numbers from 1 to n */
//     for (i = 1; i <= n; i++)
//         xor1 = xor1 ^ i;

//     /* Get the rightmost set bit in set_bit_no */
//     set_bit_no = xor1 & ~(xor1 - 1);

//     /* Now divide elements into two sets by comparing a rightmost set bit
//        of xor1 with the bit at the same position in each element.
//        Also, get XORs of two sets. The two XORs are the output elements.
//        The following two for loops serve the purpose */

//     for (i = 0; i < n; i++) {
//         if (arr[i] & set_bit_no)
//             /* arr[i] belongs to first set */
//             x = x ^ arr[i];

//         else
//             /* arr[i] belongs to second set */
//             y = y ^ arr[i];
//     }

//     for (i = 1; i <= n; i++) {
//         if (i & set_bit_no)
//             /* i belongs to first set */
//             x = x ^ i;

//         else
//             /* i belongs to second set */
//             y = y ^ i;
//     }

//     // NB! numbers can be swapped, maybe do a check ?
//     int x_count = 0;
//     for (int i=0; i<n; i++) {
//         if (arr[i]==x)
//             x_count++;
//     }
    
//     if (x_count==0)
//         return {y, x};
    
//     return {x, y};
// }