class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int inversion_count = 0;
        for (int i = 0; i < n; ++i) {
            if (!(nums[i] <= nums[(i+1)%n]))
                ++inversion_count;
        }
        return (inversion_count <= 1);
    }
};