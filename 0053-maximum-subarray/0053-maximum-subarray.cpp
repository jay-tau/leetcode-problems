class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        dp[0][false] = dp[0][true] = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            // Taking
            dp[i][true] = max(nums[i], nums[i] + dp[i - 1][true]);
            // Not taking
            dp[i][false] = max(dp[i - 1][true], nums[i]); // Not including current, starting at current

            ans = max(ans, max(dp[i][true], dp[i][false]));
        }

        // cout << "dp: " << endl; for (int j = 0; j < 2; j++) { for (int i = 0; i < n; i++) { int x = dp[i][j]; cout << x << " "; } cout << endl; }

        return ans;
    }
};