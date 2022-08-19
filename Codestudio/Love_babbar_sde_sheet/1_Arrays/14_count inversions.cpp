#include<bits/stdc++.h>
using namespace std;

// Approach-1

// long long getInversions(long long *arr, int n){
//     // Variable to store the total inversions in the array.
//     long long totalInversions = 0;

//     // Check for each element whether any smaller element is present on right side.
//     for (int i = 0; i < n; ++i){
//         for (int j = i + 1; j < n; ++j){
//             if (arr[i] > arr[j]){
//                 ++totalInversions;
//             }
//         }
//     }
//     return totalInversions;
// }

/*
    Time complexity : O(N * log(N))
    Space complexity : O(N)

    Where 'N' is the total number of elements in the array/list.
*/

// Function to merge the two subarrays.
long long merge(long long arr[], int left, int mid, int right){
    int i = left, j = mid, k = 0;
    long long invCount = 0;
    int temp[(right - left + 1)];

    while ((i < mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            ++k;
            ++i;
        }
        else{
            temp[k] = arr[j];
            invCount += (mid - i);
            ++k;
            ++j;
        }
    }

    while (i < mid){
        temp[k] = arr[i];
        ++k;
        ++i;
    }

    while (j <= right){
        temp[k] = arr[j];
        ++k;
        ++j;
    }

    for (i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }

    return invCount;
}

// Function to split two subarrays and then merge them and count inversions.
long long mergeSort(long long arr[], int left, int right){
    long long invCount = 0;

    if (right > left){
        int mid = (right + left) / 2;

        /* 
            Divide the array into two parts
            total inversion count will be the
            sum of 'INVCOUNT' of left part +
            'INVCOUNT' of right part + 'INVCOUNT' of
            their combined part.
        */
        invCount = mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);

        // Merge both parts and count their combined inversions.
        invCount += merge(arr, left, mid + 1, right);
    }
    return invCount;
}

long long getInversions(long long arr[], int n){
    return mergeSort(arr, 0, n - 1);
}

int main(){
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << getInversions(arr, n);
    return 0;
}






// int merge(int arr[],int temp[],int left,int mid,int right)
// {
//     int inv_count=0;
//     int i = left;
//     int j = mid;
//     int k = left;
//     while((i <= mid-1) && (j <= right)){
//         if(arr[i] <= arr[j]){
//             temp[k++] = arr[i++];
//         }
//         else
//         {
//             temp[k++] = arr[j++];
//             inv_count = inv_count + (mid - i);
//         }
//     }

//     while(i <= mid - 1)
//         temp[k++] = arr[i++];

//     while(j <= right)
//         temp[k++] = arr[j++];

//     for(i = left ; i <= right ; i++)
//         arr[i] = temp[i];
    
//     return inv_count;
// }

// int merge_Sort(int arr[],int temp[],int left,int right)
// {
//     int mid,inv_count = 0;
//     if(right > left)
//     {
//         mid = (left + right)/2;

//         inv_count += merge_Sort(arr,temp,left,mid);
//         inv_count += merge_Sort(arr,temp,mid+1,right);

//         inv_count += merge(arr,temp,left,mid+1,right);
//     }
//     return inv_count;
// }
// long long getInversions(long long *arr, long long int n){
//     // Write your code here.
//     long long int temp[n];
//     return _mergeSort(arr, temp, 0, n-1);
// //     return ans;
// }