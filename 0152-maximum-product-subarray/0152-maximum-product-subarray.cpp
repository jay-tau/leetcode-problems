class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prev_max = nums[0], prev_min = nums[0];
        int overall_max = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            int current_max, current_min;
            current_max = max(x, max(prev_max*x, prev_min*x));
            current_min = min(x, min(prev_max*x, prev_min*x));

            overall_max = max(overall_max, current_max);

            prev_max = max(current_max, x);
            prev_min = min(current_min, x);
        }

        return overall_max;
    }
};