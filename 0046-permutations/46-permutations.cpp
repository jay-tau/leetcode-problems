class Solution {
private:
    void f(int index, vector<int> &v, vector<int> &nums, vector<vector<int>> &ans) {
        int n = nums.size();
        if ((index >= n) || (v.size() == n)) {
            ans.push_back(v);
            return;
        }
        
        for (int i = index; i < n; ++i) {
            swap(nums[index], nums[i]); // Bring number to start
            v.push_back(nums[index]);
            
            f(index+1, v, nums, ans);
            
            v.pop_back();
            swap(nums[index], nums[i]); // Bring original number back to start
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        
        f(0, v, nums, ans);
        
        return ans;
    }
};