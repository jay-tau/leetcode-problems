class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int current_pos = 0;
         int n = nums.size();
         while (n--) {
             if (nums[current_pos] == 0) {
                 nums.erase(nums.begin() + current_pos);
                 nums.push_back(0);
             } else
                 current_pos++;
        }
    }
};