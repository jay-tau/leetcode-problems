class Solution {
private:
  int dp[100 + 1];
  int f(int i, vector<int> &nums) {
    int n = nums.size();
    
    if (i >= n) return 0;
    
    int &ans = dp[i];
    if (ans != -1) return ans;
    
    // Take it and skip next
    // Skip this and take next
    ans = max(nums[i] + f(i+2, nums), f(i+1, nums));
    
    return ans;
  }
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      memset(dp, -1, sizeof dp);
      return f(0, nums);
    }
};