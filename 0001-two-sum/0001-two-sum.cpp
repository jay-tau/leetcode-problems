class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans;
        ans.reserve(2);

        unordered_map<int, int> m; // (element, index)
    
        for (int i = 0; i < n; i++)
            auto [it, inserted] = m.insert_or_assign(nums[i], i); // Overwrite the older index

        for (int x_i = 0; x_i < n; x_i++) {
            int x = nums[x_i];
            auto it = m.find(target - x);
            if (it != m.end()) {
                auto [y, y_i] = *it;

                if (x != y || x_i != y_i) { // OR x = target / 2
                    ans.emplace_back(x_i);
                    ans.emplace_back(y_i);
                    break;
                }
            }
        }

        return ans;
    }
};