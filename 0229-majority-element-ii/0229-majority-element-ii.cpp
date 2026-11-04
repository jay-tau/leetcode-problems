class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count_a = 0, count_b = 0;
        int x_a = -1, x_b = -1;

        for (auto x : nums) {
            if (x == x_a)
                count_a++;
            else if (x == x_b)
                count_b++;
            else if (count_a <= 0) {
                x_a = x;
                count_a = 1;
            } else if (count_b <= 0) {
                x_b = x;
                count_b = 1;
            } else {
                count_a--;
                count_b--;
            }
        }

        vector<int> ans;
        ans.reserve(2);
        if (count(nums.begin(), nums.end(), x_a) > n / 3)
            ans.emplace_back(x_a);
        if (x_a != x_b && count(nums.begin(), nums.end(), x_b) > n / 3)
            ans.emplace_back(x_b);

        return ans;
    }
};