class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cur(2,0);
        vector<int> after(2,0);
        for(int i=n-1;i>=0;i--){
            for(int b = 0;b<=1;b++){
                if(b==0){
                    cur[b] = max((-prices[i]-fee)+after[1],after[0]);
                }
                else{
                    cur[b] = max(prices[i]+after[0],after[1]);
                }
                after = cur;
            }
        }
        return cur[0];
    }
};