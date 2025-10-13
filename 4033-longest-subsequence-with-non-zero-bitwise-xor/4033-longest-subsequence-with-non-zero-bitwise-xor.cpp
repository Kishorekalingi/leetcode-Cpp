class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() , tSum = 0 ,cnt = 0,res =0;
        for(int i=0;i<n;i++){
            tSum ^= nums[i];
            if(tSum == 0) cnt = 0;
            cnt++;
            res = max(res,cnt);
        }
        return res;
    }
};