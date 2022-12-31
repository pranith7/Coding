#include<bits/stdc++.h>
using namespace std;


/*
	This is a C++ class that contains a method findKthPositive() which uses a binary 
	search algorithm to find the Kth positive integer that is missing from a given 
	array of positive integers. The array is passed to the method as a vector of integers
	arr, and the value of k is specified by the parameter of the same name.

	The method begins by defining the variables i and j to represent the left and right bounds
	of the search range, respectively. It then enters a loop that continues until i is
	less than j. In each iteration of the loop, it calculates the midpoint between i and j
	and stores it in the variable mid.

	The method then checks if the difference between the midth element of the array and mid+1
	is greater than or equal to k. If it is, the method updates j to be mid and continues the loop.
	If the difference is less than k, the method updates i to be mid+1 and continues the loop.

	Finally, when the loop ends, the method returns i+k, which is the Kth positive integer that
	is missing from the array.	
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0, j=arr.size();
		while(i<j){
			int mid=i+(j-i)/2;
			if(arr[mid]-(mid+1)>=k){j=mid;}
			else{i=mid+1;}
		}
		return i+k;
    }
};