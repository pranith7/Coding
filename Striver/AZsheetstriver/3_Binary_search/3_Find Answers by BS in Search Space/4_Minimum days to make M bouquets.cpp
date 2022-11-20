#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool ispossible(long long mid,vector<int> &A,int m,int k)
    {
        int n = A.size();
        int flow = 0,bouq = 0;
        for (int j = 0; j < n; ++j) {
                   if (A[j] > mid) {
                    flow = 0;
                } else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
        if (bouq>=m) return true;
         
        return false;
    }

    int minDays(vector<int>& A, int m, int k) {
        int n = A.size(), left = 1; 
        int right = 1e9;
        if ((long long)m * k > (long long)n) return -1; // condition from problem
        
        while (left < right) {
            long long int mid = ((long long)left + right) / 2;
            if(ispossible(mid,A,m,k) == false)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};