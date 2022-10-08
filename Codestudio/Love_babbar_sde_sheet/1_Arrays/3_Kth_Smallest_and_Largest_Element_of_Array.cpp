#include <bits/stdc++.h>
using namespace std;


// vector<int> kthSmallLarge(vector<int> &arr, int n, int k) --> Approach 1
// {
//    sort(arr.begin(),arr.end());
//    vector<int> res;
//    res.push_back(arr[k-1]);
//    res.push_back(arr[n-k]);
//    sort(res.begin(),res.end()); // personal opinion [Depends on the question]
//    return res;
// }

int partition(vector<int> &arr, int left, int right, int pivotIndex) 
{
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Bring pivot element at the end of range.
    int current = left;
 for(int i = left; i < right; i++) 
    {
        if(arr[i] < pivotValue) 
        {
            swap(arr[current], arr[i]);
            current++;
        }
    }
    swap(arr[right], arr[current]);
    
    return current;
}

int quickSelect(vector<int> &arr, int left, int right, int k) 
{
    if(left == right)
    {
        return arr[left];  // Size of array is 1.
    }
    int pivotIndex = left + rand() % (right-left+1); // Note we can select Median as pivot to guaranteed O(N) complexity always.
    int partitionIndex = partition(arr, left, right, pivotIndex);

    if(partitionIndex >= k)
    {
        return quickSelect(arr, left, partitionIndex-1, k); // Recur for right subarray
    }
    
    if(partitionIndex < k-1)
    {
        return quickSelect(arr, partitionIndex+1, right, k); // Recur for left subarray.
    }

    return arr[partitionIndex];
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> result(2);
    result[0] = quickSelect(arr, 0, n-1, k);  // Kth smallest element
    result[1] = quickSelect(arr, 0, n-1, n-k+1); // Kth largest element
    return result;
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> res;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    res = kthSmallLarge(arr,n,k);
    cout<<"Output of the array "<<endl;
    for(auto i:res) 
    {   
        cout<<i<<" ";
    }
    return 0;
}