#include<bits/stdc++.h>
using namespace std;

/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship 
with packages on the conveyor belt (in the order given by weights). We may not load more weight
 than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor
 belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/

class Solution {
public:
    /*
        The function begins by defining two variables, left and right, which will be used to specify the range 
        of possible shipping weights that the function will search through. The variable left is initialized to 
        0, and right is initialized to 25000000.

        The function then iterates through the elements of the weights vector and updates the value of left to 
        be the maximum of left and the current weight. This ensures that left is at least as large as the 
        largest weight in the weights vector.

        Next, the function enters a loop that continues until left is less than right. In each iteration of 
        the loop, the function calculates the midpoint between left and right and stores it in the variable mid. 
        It then initializes the variables need and cur to 1 and 0, respectively.

        The function then enters a second loop that iterates through the elements of the weights vector. 
        For each element, it adds the weight to the variable cur and checks if cur is now greater than mid. 
        If it is, the function resets cur to 0 and increments need by 1. The second loop continues until 
        either all the weights have been processed or need is greater than D.

        If need is greater than D, the function updates left to be mid + 1 and continues the outer loop. 
        If need is less than or equal to D, the function updates right to be mid and continues the outer loop.

        Finally, when the loop ends, the function returns the value of left, which is the minimum possible
         shipping weight that can be used to ship the given set of weights within the specified number of days.
    */
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 25000000;
        for (int w: weights)
            left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size() && need <= D; cur += weights[i++])
                if (cur + weights[i] > mid)
                    cur = 0, need++;
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};