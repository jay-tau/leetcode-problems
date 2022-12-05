class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l_pointer = 0, r_pointer = (nums.size() - 1);
        for (int i = 0; i < nums.size(); i++) {
            int current_element = nums[i];
            if (current_element % 2 == 0) {
                ans[l_pointer] = current_element;
                l_pointer++;
            } else {
                ans[r_pointer] = current_element;
                r_pointer--;
            }
        }
        return ans;
    }
};