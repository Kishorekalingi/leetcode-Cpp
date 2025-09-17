class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int mini  = prices[0];
        for(int i=0;i<prices.size();i++){
            if(mini < prices[i]){
                maxPro += prices[i]- mini;
                mini = prices[i];
            }
            else{
                mini = min(mini,prices[i]);
            }
        }
        return maxPro;
    }
};