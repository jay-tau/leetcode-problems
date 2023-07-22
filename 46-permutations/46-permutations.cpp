class Solution {
private:
    void f(vector<int>&v, vector<bool> &remaining, vector<vector<int>> &ans, vector<int> &nums) {
        int n = nums.size();
        if (v.size() == n) {
            ans.push_back(v);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (remaining[i]) {
                v.push_back(nums[i]);
                remaining[i] = false;
                f(v, remaining, ans, nums);
                v.pop_back();
                remaining[i] = true;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> remaining(nums.size(), true);
        
        f(v, remaining, ans, nums);
        
        return ans;
    }
};