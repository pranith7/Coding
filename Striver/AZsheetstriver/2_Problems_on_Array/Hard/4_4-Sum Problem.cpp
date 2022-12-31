#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;
        /*
                The above code is an implementation of the four sum algorithm, which is a variation of the
                well-known three sum algorithm. It is used to find all unique quadruplets in an array that 
                sum up to a given target value.

                The algorithm starts by sorting the input array in ascending order. Then, it iterates over the 
                array, fixing the first element and treating the rest of the array as a three sum problem. To do 
                this, it calculates a target value for the three sum problem by subtracting the fixed element from 
                the target value. Then, it iterates over the remaining elements of the array, fixing the second 
                element and treating the rest of the array as a two sum problem.

                To solve the two sum problem, the algorithm uses a two-pointer approach. It initializes two pointers, 
                one at the start of the array and the other at the end, and moves them towards each other while checking 
                if the sum of the elements pointed by the pointers is equal to the target value. If it is, the algorithm
                adds the four elements to the result vector. If it is less than the target value, the algorithm increments
                the left pointer. If it is greater than the target value, the algorithm decrements the right pointer.

                After each iteration, the algorithm checks for duplicates of the fixed elements and skips them to 
                avoid adding duplicate quadruplets to the result vector. It does this by checking if the current element
                 is equal to the previous one and, if it is, incrementing or decrementing the appropriate pointer.

                Finally, the function returns the result vector containing all the unique quadruplets that sum up to the target value.
        */
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
            
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> v{1,0,-1,0,-2,2};
    
    vector<vector<int>> sum=obj.fourSum(v,0);
    cout<<"The unique quadruplets are"<<endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}