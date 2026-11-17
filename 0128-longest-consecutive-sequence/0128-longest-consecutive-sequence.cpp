class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for (int x : s) {
            if (s.contains(x - 1))
                continue;

            // At smallest element
            int possible_ans = 1;
            while (true) {
                if (s.contains(x + 1)) {
                    possible_ans++;
                    x++;
                } else {
                    ans = max(ans, possible_ans);
                    break;
                }
            }
        }

        return ans;
    }
};