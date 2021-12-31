#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fo(i,a,n) for(int i=a;i<n;i++)
#define foinv(i,a,n) for(int i=a;i>=n;i--)
#define inp(arr,i,a,n) for(int i = a;i<=n;i++) cin >> arr[i];
#define dis(arr,i,a,n) for(int i = a;i<=n;i++) cout<<arr[i]<<" ";cout<<endl;
#define lb(arr,k) lower_bound(arr.begin(),arr.end(),k);
#define ub(arr,k) upper_bound(arr.begin(),arr.end(),k);
#define srt(arr) sort(arr.begin(),arr.end());
#define rev(arr) reverse(arr.begin(),arr.end());
#define ump unordered_map
#define mp map
#define pb emplace_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll,ll>
#define endl "\n"
#define ff first
#define ss second


int fact(int n)
{
    //Base case
    if(n==1) return 1;
    //recursive assumption
    int subproblem = fact(n-1);
    //self work
    return n*subproblem;
    //return(n<=1) ? 1 : n*(fact(n-1)); 
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<fact(10);
    return 0;
}