class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int max_sum = INT_MIN, current_sum = 0;
        for (int i = 0; i < n; i++) {
            current_sum += nums[i];
            
            max_sum = max(max_sum, current_sum);
            current_sum = max(current_sum, 0); // If overall sum is -ve, then reset to 0
        }
        
        return max_sum;
    }
};