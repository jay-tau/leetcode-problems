class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l_pointer = 0, r_pointer = (nums.size() - 1);
        while (l_pointer < r_pointer) { // 1 ... 0
            if ((nums[l_pointer] % 2) > (nums[r_pointer] % 2)) {
                swap(nums[l_pointer], nums[r_pointer]);
                l_pointer++;
                r_pointer--;
            } else if (nums[l_pointer] % 2 == 1) { // 1 ... 1
                r_pointer--;
            } else if (nums[r_pointer] % 2 == 0) { // 0 ... 0
                l_pointer++;
            } else { // 0 ... 1
                l_pointer++;
                r_pointer--;
            }
        }
        return nums;
    }
};