#include<bits/stdc++.h>
using namespace std;

/*
    The function begins by checking if m is greater than n. If it is, the function calls itself with the arrays 
    and their lengths swapped. This is done to ensure that the binary search that follows is performed on the 
    smaller of the two arrays, which will make the search more efficient.

    The function then defines the variables low, high, and medianPos. low and high are used to specify the range 
    of indices being searched in nums1, and medianPos is the position of the median in the combined array of nums1
    and nums2.

    The function then enters a loop that continues until low is less than or equal to high. In each iteration of
    the loop, it calculates the midpoint between low and high and stores it in the variable cut1. It then 
    calculates the corresponding index in nums2 using cut1 and medianPos, and stores it in the variable cut2.

    The function then defines the variables l1, l2, r1, and r2, which represent the elements just before and after
    the cuts in nums1 and nums2, respectively. If the cuts fall at the beginning or end of an array, the 
    corresponding variables are initialized to the minimum or maximum values of int to ensure that they do not
    affect the comparison that follows.

    Next, the function checks if the elements just before the cuts are less than or equal to the elements just
    after the cuts. If they are, the function has found the correct cuts and it proceeds to calculate and return
    the median. If the elements just before the cuts are greater than the elements just after the cuts, the function
    updates low or high and continues the loop.

    If the combined length of the arrays is odd, the median is the maximum of the elements just before the cuts. 
    If the combined length is even, the median is the average of the maximum of the elements just before the cuts
     and the minimum of the elements just after the cuts.
*/
float median(int nums1[],int nums2[],int m,int n) {
    if(m>n)
        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array
        
    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}

int main() {
    int nums1[] = {1,4,7,10,12};
    int nums2[] = {2,3,6,15};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"The Median of two sorted arrays is"<<fixed<<setprecision(5)
    <<median(nums1,nums2,m,n);
    return 0;
}