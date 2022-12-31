#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int sum = 0;
        // for(int i=0;i<prices.size()-1;i++)
        // {
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         if(prices[j] > prices[i])
        //             sum = max(sum,prices[j]-prices[i]);
        //     }
        // }
        // return sum;

        /*
            The maxProfit function takes a vector of integers called prices as input, and returns the 
            maximum possible profit that can be made by buying and selling a single stock on a single day.

            The function first initializes a variable profit to 0 and a variable minimal to the maximum 
            possible value of an int.It then enters a loop that iterates over the elements of the prices vector.

            For each element prices[i], the function updates minimal to the minimum of minimal and prices[i]. 
            It then updates profit to the maximum of profit and the difference between prices[i] and minimal.

            After the loop ends, the function returns the value of profit.

            The commented-out code at the beginning of the function is a brute-force solution that checks 
            every possible pair of buy and sell prices and returns the maximum profit. This solution has a 
            time complexity of O(n^2), since it requires two nested loops to check every pair of prices.

            The code that is currently being executed has a time complexity of O(n), since it only requires 
            a single pass through the prices vector to find the maximum profit. It uses the variable minimal 
            to keep track of the minimum price seen so far, and updates profit with the maximum difference 
            between the current price and the minimum price seen so far.
        */
        int profit = 0;
        int minimal = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minimal = min(minimal,prices[i]);
            profit = max(profit,prices[i]-minimal);
        }
        return profit;
        

    }
};