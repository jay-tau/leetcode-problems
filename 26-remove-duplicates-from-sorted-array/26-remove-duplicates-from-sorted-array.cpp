class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last_element = nums[0];
        int current_index = 1;
        for (int i = 1; i < nums.size(); i++) {
            int current_element = nums[i];
            if (current_element != last_element) {
                nums[current_index] = current_element;
                last_element = current_element;
                current_index++;
            }
        }
        return current_index;
    }
};