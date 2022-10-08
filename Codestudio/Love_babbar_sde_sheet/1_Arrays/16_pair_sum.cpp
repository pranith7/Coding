#include<bots/stdc++.h>
using namespace std;


int pairSum(vector<int> &arr, int n, int target){
	// Write your code here.
    int start = 0;
    int end = n-1;
    long long count = 0;
    while(start<end)
    {
        if(arr[start] + arr[end] == target)
        {
            count++;
            start++;
            end--;
        }
        else if(arr[start]+arr[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    
    if(count) return count;
    return -1;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << pairSum(arr, n, target);
    return 0;
}