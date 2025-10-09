class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        vector<int> after(2*k+1,0);
        vector<int> cur(2*k+1,0);
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            for(int t = 2*k-1;t>=0;t--){
                if(t%2 ==0){
                    cur[t] = max(-prices[i] + after[t+1],after[t]);
                }
                else{
                    cur[t] = max(prices[i] + after[t+1],after[t]);
                }
            }
            after = cur;
        }
        return after[0];

    }
};