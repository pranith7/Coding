#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
vector<int> threeWayPartition(vector<int> &arr, int n, int a, int b)
{
    // Write your code here
    int low = 0,high = n-1,mid = 0;
    while(mid<=high)
    {
            if(arr[mid]<a)
            {
                swap(arr[mid],arr[low]);
                mid++;
                low++;
            }
            else if(arr[mid]>=a and arr[mid]<=b)
            {
                mid++;
            }
            else
            {
                swap(arr[mid],arr[high]);
                high--;
            }
    }
    
    return arr;
}

int main()
{
    int n;
    cin >> n ;  
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a, b;
    cin >> a >> b;
    threeWayPartition(arr, n, a, b);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}