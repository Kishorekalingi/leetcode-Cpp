class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7) return (n*(n+1))/2;
        int first= n/7;
        int r = n%7;
        int ans =0;
        for(int i=0;i<first;i++){
            ans+=((28)+i*7);
        }
        ans += ((r*(r+1))/2)+(r*first);
        return ans;
    }
};