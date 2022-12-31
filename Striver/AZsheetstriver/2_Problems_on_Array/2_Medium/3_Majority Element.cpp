#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        /*
            The majorityElement function takes a vector of integers called nums as input, and returns 
            the element that appears more than half of the time in the vector.

            The function uses a linear scan to find the majority element. It starts by initializing two
            variables: majority, which will store the current candidate for the majority element, and 
            count, which will keep track of the number of times the current candidate has been seen. 
            The function initializes majority to the first element of the vector and count to 1.

            The function then enters a loop that iterates over the remaining elements of the vector. 
            For each element nums[i], the function checks if it is equal to the current candidate element 
            majority. If it is, the function increments count by 1. If it is not, the function decrements 
            count by 1.

            If count becomes 0, this means that the current candidate element has been seen an equal number
            of times as its opposite, and a new candidate element needs to be chosen. The function sets 
            majority to the current element nums[i] and resets count to 1.

            After the loop ends, the function returns the value of majority, which is the element that appears
            more than half of the time in the vector if it exists.
            
        */
        // vector<int> ans;
        int n = nums.size();
        int majority = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == majority) {
            count++;
            } else {
            count--;
            }
            if (count == 0) {
            majority = nums[i];
            count = 1;
            }
        }
        return majority;
    }
    
};
