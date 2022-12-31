#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr)
{   

    /*
        The function starts by declaring a variable n and assigning it the size of the input vector. 
        It then enters a loop that iterates n-1 times. On each iteration, the loop sets the variable min_idx
        to the current index i.

        Inside the inner loop, the function compares the elements at index j and min_idx and updates min_idx if
        the element at index j is smaller. The inner loop iterates through the unsorted portion of the list starting
        at index i+1 and ending at the last element in the list.

        After the inner loop finishes, the function checks if min_idx is different from i. If it is, the function 
        swaps the elements at index min_idx and i using the swap function from the algorithm library.

        When the outer loop finishes, the list is sorted in ascending order. The function then returns control to 
        the calling function.
    */
    int n = arr.size();
    for(int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < arr.size(); j++)
        {
            if(arr[j] < arr[min_idx]) min_idx = j;

        }
        if(min_idx!=i)  swap(arr[min_idx], arr[i]);
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}