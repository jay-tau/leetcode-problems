class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for (int a = n - 1; a > 0; a--) {
            if (nums[a - 1] < nums[a]) { // Not descending
                int i = a - 1;
                int x = nums[i];

                // Find the smallest element which is > x

                // Right array is already ordered
                int j = n - 1;
                while (nums[j] <= x)
                    j--;

                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        // Entire array is descending (last permutation)
        reverse(nums.begin(), nums.end());
    }
};