class Solution {
private:
    int fun(int i, int buy,vector<int>& arr,vector<vector<int>>& dp){
        if(i == arr.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max((-arr[i] + fun(i+1,0,arr,dp)),(fun(i+1,1,arr,dp)));
        }
        else{
            profit = max((arr[i] + fun(i+1,1,arr,dp)),fun(i+1,0,arr,dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fun(0,1,prices,dp);
    }
};