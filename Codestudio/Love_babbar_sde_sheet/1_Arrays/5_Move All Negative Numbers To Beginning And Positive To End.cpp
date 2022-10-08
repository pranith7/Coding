#include <bits/stdc++.h>
using namespace std;

vector < int > separateNegativeAndPositive(vector < int > & nums) {
    // 'j' stores the index of the leftmost positive element.
    // int j = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] < 0) {
    //         // Current element is negative.
    //         if (i != j) { swap(nums[i], nums[j]);}
    //         ++j;
    //     }
    // }
    // return nums;

    int n = nums.size(); //Array size --> Personal approach
    int j = n - 1;
    for(int i = n-1;i>=0;i--)
    {
        if(nums[i] < 0 )
        {
            if(i!=j)
            {
                swap(nums[i],nums[j]);
                j--;
            }
        }
    }
    return nums;
}

int main()
{   
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    res = separateNegativeAndPositive(arr);
    cout<<"Output sorted array "<<endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}