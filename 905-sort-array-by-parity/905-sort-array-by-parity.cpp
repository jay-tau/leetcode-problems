class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l_pointer = 0, r_pointer = (nums.size() - 1);
        while (l_pointer < r_pointer) {
            int l_element = nums[l_pointer], r_element = nums[r_pointer];
            if ((l_element % 2) > (r_element % 2)) { // 1 ... 0
                swap(nums[l_pointer], nums[r_pointer]);
                l_pointer++;
                r_pointer--;
            } else if (l_element % 2 == 1) { // 1 ... 1
                r_pointer--;
            } else if (r_element % 2 == 0) { // 0 ... 0
                l_pointer++;
            } else { // 0 ... 1
                l_pointer++;
                r_pointer--;
            }
        }
        return nums;
    }
};