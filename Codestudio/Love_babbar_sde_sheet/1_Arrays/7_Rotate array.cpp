#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int k)
{    
    vector<int> temp;
    for(int i=0;i<k;i++)
    {
        temp[i] = arr[i];
        arr[i] = arr[i+k];
        arr[i+k] = temp[i];
    }

}

int main() {
    //Write your code here
    int n;
    cin>>n;
    vector<int> arr(n);
    int k;
    cin>>k;
    solve(arr,k);
    return 0;
}