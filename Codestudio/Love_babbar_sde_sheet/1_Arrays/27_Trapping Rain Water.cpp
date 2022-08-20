#include <bits/stdc++.h>
using namespace std;


/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where N is the total number of elevations.
*/

#include <climits>

long getTrappedWater(long *arr, int n){

    //Reference point.
    int peak = 0;

    // Result.
    long ans = 0L;


    if (n == 0) {
        return 0L;
    }

    long peakVal = arr[0];

    // Moving left to right.
    for (int i = 0; i < n; i++) {
        if (arr[i] >= peakVal) {
            peak = i;
            peakVal = arr[i];
        }
    }

    // Initialising a min value.
    long maxSoFar = LONG_MIN;
    long countSubmerged = 0L;
    long submergedArea = 0L;

    // Traversing over a peak.
    for (int i = 0; i <= peak; i++) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    // Initialising a min value.
    maxSoFar = LONG_MIN;
    countSubmerged = 0L;
    submergedArea = 0L;

    // Moving right to left.
    for (int i = n - 1; i >= peak; i--) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    return ans;
}

long getTrappedWater(long *arr, int n){
    // Write your code here.
    long int prefix[n],suffix[n];
    long long ans = 0;
    prefix[0] = arr[0];
    suffix[n-1] = arr[n-1];
    for(int i=1;i<n;i++)
    {
        prefix[i] =max(prefix[i-1],arr[i]); 
    }
    for(int i=n-2;i>=0;i--)
    {
        suffix[i] = max(suffix[i+1],arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans += (min(prefix[i],suffix[i])-arr[i]);
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    long *arr = new long[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<getTrappedWater(arr,n);
    return 0;
}