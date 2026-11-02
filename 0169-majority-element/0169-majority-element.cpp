class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1, majority_candidate = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];
            if (x == majority_candidate)
                count++;
            else {
                count--;
                if (count < 0) {
                    count = 1;
                    majority_candidate = x;
                }
            }
        }

        return majority_candidate;
    }
};