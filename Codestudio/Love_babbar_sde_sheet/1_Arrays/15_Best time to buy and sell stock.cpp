#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit = 0;
    int minimal = INT_MAX;
    for(int i=0;i<prices.size();i++)
    {
       minimal = min(minimal,prices[i]);
       profit = max(profit,prices[i]-minimal);
    }
    
    return profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i){
        cin >> prices[i];
    }
    cout << maximumProfit(prices) << endl;
    return 0;
}