#include<bits/stdc++.h>
using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	// Write your code here.
   
        vector<int> ans;
    
    int limit = n/k;
    unordered_map<int, int> count;
    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    
    for(auto it: count){
        if(it.second >= limit){
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans = countTheNumber(arr,n,k);
    cout<<ans.size()<<endl;
    return 0;
}