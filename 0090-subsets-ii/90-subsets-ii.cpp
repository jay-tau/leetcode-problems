class Solution {
private:
    void powerSet(int index, vector<int> &v, vector<int> &arr, vector<vector<int>> &ans, int n) {        
        ans.push_back(v);

        // cout << index << ": ";for (auto x: v) cout <<x << " ";cout <<endl;

        // Add each element
        for (int i = index; i < n; ++i) {
            if ((i != index) && (arr[i-1] == arr[i])) // Don't add same element twice
                continue;
            
            v.push_back(arr[i]);
            powerSet(i+1, v, arr, ans, n);
            v.pop_back(); // No need to make recursive call, as ans already has v
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> v;
        vector<vector<int>> ans;

        powerSet(0, v, nums, ans, nums.size());

        return ans;
    }
};