class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int k = *max_element(nums.begin(), nums.end());
        if (k < 0) {
            return k;
        }
        int tsum = 0;
        int maxsum = INT_MIN, maxCnt = 0;
        int minsum = INT_MAX, minCnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            tsum += nums[i];

            maxCnt = max(maxCnt + nums[i], nums[i]);
            maxsum = max(maxsum, maxCnt);

            minCnt = min(minCnt + nums[i], nums[i]);
            minsum = min(minsum, minCnt);
        }
        return max(maxsum, tsum - minsum);
    }
};