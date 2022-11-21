class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int current_count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count = max(count, ++current_count);
            else
                current_count = 0;
        }
        return count;
    }
};