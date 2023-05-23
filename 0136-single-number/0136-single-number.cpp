class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // x^x = 0, 0^x = x
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            ans ^= nums[i];
        return ans;
    }
};