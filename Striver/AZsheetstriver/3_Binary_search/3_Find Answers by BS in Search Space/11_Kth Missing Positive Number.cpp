#include<bits/stdc++.h>
using namespace std;

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