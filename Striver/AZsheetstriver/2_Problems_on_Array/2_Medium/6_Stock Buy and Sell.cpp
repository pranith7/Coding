class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int sum = 0;
        // for(int i=0;i<prices.size()-1;i++)
        // {
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         if(prices[j] > prices[i])
        //             sum = max(sum,prices[j]-prices[i]);
        //     }
        // }
        // return sum;
        int profit = 0;
        int minimal = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minimal = min(minimal,prices[i]);
            profit = max(profit,prices[i]-minimal);
        }
        return profit;
        

    }
};