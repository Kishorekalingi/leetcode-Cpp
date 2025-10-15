class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() , tSum = 0 ,cnt = 0;
        for(int i=0;i<n;i++){
            tSum ^= nums[i];
            if(nums[i] == 0) cnt++;
        }
        if(tSum != 0 ) return n;
        else{
            if(cnt == n) return 0;
        }
        return n-1;
    }
};