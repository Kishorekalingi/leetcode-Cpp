class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0 ;
        int mini = prices[0];
        for(int i=0;i<prices.size();i++){
            p = max(p,prices[i] - mini);
            mini = min(mini, prices[i]);
           
        }
        return p;
    }
};