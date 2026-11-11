class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int a = nums[i], b = nums[j];

                int left = j + 1, right = n - 1;
                while (left < right) {
                    int c = nums[left], d = nums[right];
                    long long sum = 0LL + a + b + c + d;
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else { // Found a match
                        // Add the answer first
                        ans.push_back({a, b, c, d});
                        // Jump to the next unique elemnent
                        left++;
                        right--;
                        while (left < right && nums[left] == c)
                            left++;
                        while (left < right && nums[right] == d)
                            right--;
                    }
                }
            }
        }

        return ans;
    }
};