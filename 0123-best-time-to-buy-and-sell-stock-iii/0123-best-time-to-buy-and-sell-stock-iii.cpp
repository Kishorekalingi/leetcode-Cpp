class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            for(int b =0;b<=1;b++){
                for(int c = 1;c<=2;c++){
                    if(!b){
                        cur[b][c] = max(-prices[i] + after[1][c],after[0][c]);
                    }
                    else{ 
                        cur[b][c] = max(after[1][c], prices[i]+ after[0][c-1]);
                    }
                }
                
            }
            after = cur;
        }
        
        return after[0][2];

    }
};