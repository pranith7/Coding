//Given two numbers a and b calculate a^b recursively
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


int solve(int a,int b)
{
    //Base case
    if(b==0) return 1;
    if(b==1) return a; 
    //Recursive Assumption
    // int ans = a*solve(a,b-1);
    int ans = solve(a,b/2);//updated one 
    //Self work
    if(b%2==0)
    {
        return ans*ans;
    }
    else
    {
        return a*ans*ans;
    }

}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<solve(4,4);
    return 0;
}