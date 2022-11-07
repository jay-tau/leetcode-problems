class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int current_index = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            if (element != val) {
                nums[current_index] = element;
                current_index++;
                count++;
            }
        }
        return count;
    }
};