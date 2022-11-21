class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 0 <= nums[i] <= 50
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = 1000;
                ans--;
            }
        }
        sort(nums.begin(), nums.end());
        return ans;
    }
};