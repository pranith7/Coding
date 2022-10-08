#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{   
    //Base case
    if(n==1)
    {
      cout<<n<<" ";
      return;
    }
    //Recursive Approach
    solve(n-1);
    //Calculation
    cout<<n<<" ";

}

int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}