class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = (nums[i]<0) ? -nums[i] : nums[i];
        
        sort(nums.begin(), nums.end());
        
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ans[i] = (nums[i] * nums[i]);
        
        return ans;
    }
};