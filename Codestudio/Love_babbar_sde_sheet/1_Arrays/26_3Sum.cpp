#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

   vector<vector<int>> ans;
   sort(arr.begin() , arr.end());
   int left , right ;
   for(int i = 0 ; i<n ; i++)
   {
       left = i+1 ;
       right = n-1;

       while(left<right)
       {
           if(arr[left]+arr[right]+arr[i] == K)
           {
               ans.push_back({arr[i], arr[left], arr[right]});
               int x = arr[left];
               int y = arr[right];

               //skipping same elements
               while(left<right && arr[left]==x){
                   left++ ;
               }
                  while(left<right && arr[right]==y){
                   right--;
               }
           }
           else if(arr[left]+arr[right]+arr[i] < K){
               left++;
           }
           else{
               right--;
           }
       }
       //skipping same ith element
        while(i+1<n && arr[i]==arr[i+1]){
           i++ ;
       }
   }
   return ans;
}

int main()
{
    int n , K ;
    cin>>n>>K;
    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>> ans = findTriplets(arr, n, K);
    for(int i = 0 ; i<ans.size() ; i++)
    {
        for(int j = 0 ; j<ans[i].size() ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}