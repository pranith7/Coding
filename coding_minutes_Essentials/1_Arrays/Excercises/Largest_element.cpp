#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    int largest_element = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>largest_element)
        {
            largest_element = arr[i];
        }
    }
     return largest_element;
}