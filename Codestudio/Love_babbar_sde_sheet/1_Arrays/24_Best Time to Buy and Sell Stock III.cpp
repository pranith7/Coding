#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    int profit;
    if(n==0) return 0;
    vector<int> left(n),right(n);
    int leftmin = prices[0];
    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1],prices[i]-leftmin);
        leftmin = min(leftmin,prices[i]);
    }
    int rightmax = prices[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i] = max(right[i+1],rightmax-prices[i]);
        rightmax = max(rightmax,prices[i]);
    }
    
    profit = right[0];
    for(int i=1;i<n;i++)
    {
        profit = max(profit,left[i-1]+right[i]);
    }
    return profit;
    
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    cout<<maxProfit(prices,n)<<endl;
    return 0;
}