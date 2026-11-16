class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans;
        ans.reserve(2);

        unordered_map<int, int> m; // (element, index)
        m.reserve(n);
    
        for (int x_i = 0; x_i < n; x_i++) {
            int x = nums[x_i];

            // Search
            auto it = m.find(target - x);
            if (it != m.end()) {
                auto [y, y_i] = *it;

                if (x_i != y_i) {
                    ans.emplace_back(x_i);
                    ans.emplace_back(y_i);
                    break;
                }
            }

            // Insert
            auto [_, _] = m.insert_or_assign(x, x_i); // Overwrite the older index
        }

        return ans;
    }
};