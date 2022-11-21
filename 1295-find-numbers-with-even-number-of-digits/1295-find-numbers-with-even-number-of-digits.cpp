class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num_of_digits = floor(log10(nums[i]))+1;
            if (num_of_digits % 2 == 0)
                count++;
        }
        return count;
    }
};