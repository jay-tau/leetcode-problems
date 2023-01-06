class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // O(n) time and O(1) space
        int n = nums.size();
        // If i is present, set nums[i-1] as negative
        for (int i = 0; i < n; i++) {
            int element = abs(nums[i]);
            nums[element-1] = min(nums[element-1], -nums[element-1]);
        }
        // If element at index i is positive, then append (i+1) to answer
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int element = nums[i];
            if (element > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};