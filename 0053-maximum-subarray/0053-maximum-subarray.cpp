class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_max = 0, overall_max = INT_MIN;

        for (int x: nums) {
            current_max = max(x, current_max + x); // Currently running subarray (take x) or reset the subarray
            overall_max = max(overall_max, current_max); // If currently running subarray is best
        }

        return overall_max;
    }
};