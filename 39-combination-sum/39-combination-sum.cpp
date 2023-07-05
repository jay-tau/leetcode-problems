class Solution {
private:
    void f(int index, vector<int> &v, int target, vector<vector<int>> &ans, vector<int> &arr) {
        if (target == 0) {
            ans.push_back(v); // Target reached
            return;
        }
        if (target < arr[0])
            return; // Dead end
        
        for (int i = index; i >= 0; --i) {
            if (arr[i] > target)
                continue;
            
            v.push_back(arr[i]);
            f(i, v, (target-arr[i]), ans, arr);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> v;
        
        f(n-1, v, target, ans, candidates);
        
        return ans;
    }
};