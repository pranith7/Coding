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

bool sorted(int a[], int size)
{
    if(a.size() == 0 || size == 1 )
    {
        return true;
    }

    bool issmalleroutput = sorted(a+1, size - 1);
    if(!issmalleroutput) return false;
    if(a[0]>a[1]) ? return false; : return true;
    
}

void solve()
{   
    int n;
    cin>>n;
    vi a;
    fo(i,0,n)
    {
        cin>>a[i];
    }
    cout<<sorted(a);
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}