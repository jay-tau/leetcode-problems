class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // O(n) by using 2 pointers. 
        int left = 0, right = nums.size() - 1;
        vector<int> ans(nums.size());
        
        for (int i = ans.size()-1; i >= 0; i--) {
            int left_element = (nums[left] * nums[left]), right_element = (nums[right] * nums[right]);
            if (left_element > right_element) {
                ans[i] = left_element;
                left++;
            } else {
                ans[i] = right_element;
                right--;
            }
        }
        return ans;
    }
};