#include<bits/stdc++.h>
using namespace std;

// Xor Based Solution
int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
       ans = ans^arr[i];
       ans = ans^i;
   }
   return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans = findDuplicate(arr);
    cout<<ans<<endl;
    return 0;
}
