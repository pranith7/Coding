#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    //Base case//01123581321
    if(n==0) return 0;
    if(n==1) return 1;
    //Recursive approach
    int ans = solve(n-1) + solve(n-2);
    //Calulation
    return ans;
}


int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}