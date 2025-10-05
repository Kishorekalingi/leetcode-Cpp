class Solution {
public:
    
    int maxArea(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int h =n-1;
        int ans = INT_MIN;
        while(l<h){
            ans = max(ans, (h-l)*min(nums[l],nums[h]));
            if(nums[l] < nums[h]){
                l++;
            }
            else if(nums[l] >=nums[h] ) h--;
        }
        return ans;
    }
};