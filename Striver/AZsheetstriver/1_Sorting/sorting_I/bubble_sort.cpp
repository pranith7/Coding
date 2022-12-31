#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr)
{   
    /*
        The bubble_sort function begins by setting a flag called swapped to true to start the loop. It then enters the loop and sets the flag to false at the beginning of each iteration. The loop continues as long as the flag is true.
Inside the loop, the function compares adjacent pairs of items and swaps them if they are in the wrong order. After each iteration, the flag is set to true if a swap occurred, and to false if no swaps occurred.

The function uses the swap function from the algorithm library to swap the values of two variables.
When the loop finishes, the list is sorted in ascending order. The function then returns control to the calling function.

In the main function, a vector of integers called list is created and initialized with the values 5, 3, 2, 8, 1, and 4. The bubble_sort function is called with list as an argument to sort it.

Finally, the main function uses a range-based for loop to print the sorted list to the console. The loop iterates through each element in the list and prints it to the console separated by a space.
    */
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for(int i = 0; i < arr.size()-1;i++)
        {
            if(arr[i]>arr[i+1]){

                swap(arr[i],arr[i+1]);
                swapped = true;
            }
        }
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
    bubble_sort(arr);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}