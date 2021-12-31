/*

Q:- you are given a 2D matrix of dimension(n*m) you will start from top left cell and you want to
    go to bottom right. AAt each point you can move either right or down. Print & count all possible 
    paths 
*/

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


void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vi> a(n,vi(m));
    fo(i,0,n)
    {
        fo(j,0,m)
        {
            cin>>a[i][j];
        }
    }
    

}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}