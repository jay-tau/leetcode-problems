class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int length = nums.size();
        // vector<int> prefixSums(length);
        for (int i = 1; i < length; i++) {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};