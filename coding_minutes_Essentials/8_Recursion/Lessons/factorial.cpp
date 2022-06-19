#include<bits/stdc++.h>
using namespace std;


int solve(int n)
{
    //Base case
    if(n==1) return 1;
    //Recursive approach
    int ans = n * solve(n-1);
    //closing statement
    return ans;

}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}