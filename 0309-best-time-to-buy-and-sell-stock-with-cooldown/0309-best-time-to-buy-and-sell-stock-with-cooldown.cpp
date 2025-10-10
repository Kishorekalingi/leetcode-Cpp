class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0);       
        vector<int> front1(2, 0);    
        vector<int> front2(2, 0); 
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                if(b==0){
                    cur[b] = max(-prices[i]+ front1[1],front1[0]);
                }
                else{
                    cur[b] = max(prices[i]+ front2[0],front1[1]);
                }
                
            }
            front2 = front1;
            front1 = cur;
        }
        return cur[0];
    
    }
};