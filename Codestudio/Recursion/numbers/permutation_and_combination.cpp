//n members are given they can either go alone or can go in with pair
//a,b,c->{a,b,c},{ab,c},{bc,a},{ca,b}



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
//

int solve(int n)
{
    int no_of_Ways;
    //Base case
    if(n==1 or n==2) return n;
    //recursive relation
    no_of_Ways = solve(n-1) + (n-1)*solve(n-2);
    //self work
    return no_of_Ways;
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<solve(3);
    return 0;
}