#include<bits/stdc++.h>
using namespace std;



/*
    Time Complexity: O( N * M * log(M) )
    Space Complexity: O( M )
    
    where 'N' is the total number of elements and 'M' is size of subarray for which you need to find median.
*/

vector<double> findMedian(vector<int> &arr, int n, int m)
{
    vector<double> ans;
    for (int i = 0; i + m - 1 < n; i++)
    {
        vector<int> v;

        for (int j = i; j < i + m; j++)
        {
            v.push_back(arr[j]);
        }

        sort(v.begin(), v.end());

        double median;
        if (m % 2 == 1)
        {
            median = v[m / 2];
        }
        else
        {
            median = ((double)v[m / 2 - 1] + v[m / 2]) / 2.0;
        }

        ans.push_back(median);
    }

  return ans;
}

/*
    Time Complexity: O(N * log(M))
    Space Complexity: O(M)
    
    Where 'N' is the total number of elements and 'M' is size of subarray for which you need to find median.
*/

vector < double > findMedian(vector < int > arr, int n, int m) {
    vector < double > ans;
    multiset < int > window(arr.begin(), arr.begin() + m);

    auto mid = next(window.begin(), m / 2);
    ans.push_back((double( * mid) + * prev(mid, 1 - m % 2)) / 2.0);

    for (int i = m; i < n; i++) {

        window.insert(arr[i]);
        if (arr[i] < * mid) {
            mid--;
        }

        if (arr[i - m] <= * mid) {
            mid++;
        }

        window.erase(window.lower_bound(arr[i - m]));
        ans.push_back((double( * mid) + * prev(mid, 1 - m % 2)) / 2.0);
    }

    return ans;
}

vector<double> findMedian(vector<int> &arr, int n, int m)
{
	// Write Your Code here.
    multiset<int>maxheap;
    multiset<int>minheap;
    vector<double>res;
    for(int i=0;i<n;i++){
        int num= arr[i];
        if(!minheap.empty() && num>*minheap.begin()){
            minheap.insert(num);
            if(minheap.size() - maxheap.size() >=1){
                int ele= *minheap.begin();
                minheap.erase(minheap.begin());
                maxheap.insert(ele);
            }
        }else{
            maxheap.insert(num);
            if(maxheap.size() - minheap.size() >1){
                int ele= *maxheap.rbegin();
                maxheap.erase(maxheap.find(*maxheap.rbegin()));
                minheap.insert(ele);
            }
        }
        int size= minheap.size() + maxheap.size();
        if(i>=m-1){
            if(size%2!=0){
                double ele= *maxheap.rbegin();
                res.push_back(ele);
            }else{
                double ele= *maxheap.rbegin() + *minheap.begin();
                ele= ele/2.0;
                res.push_back(ele);
            }
            
            int temp= arr[i-m+1];
            if(!minheap.empty() && temp >= *minheap.begin()){
                minheap.erase(minheap.find(temp));
                if(maxheap.size() - minheap.size() >1){
                    int ele= *maxheap.rbegin();
                    maxheap.erase(maxheap.find(ele));
                    minheap.insert(ele);
                }
            }else{
                maxheap.erase(maxheap.find(temp));
                if(minheap.size() - maxheap.size() >=1){
                    int ele= *minheap.begin();
                    minheap.erase(minheap.find(ele));
                    maxheap.insert(ele);
                }
            }
        }
    }
    
    return res;
}