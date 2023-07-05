class Solution {
private:
    void f(int index, int target, vector<int> &v, vector<int> &arr, vector<vector<int>> &ans) {
        int n = arr.size();
        
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        
        for (int i = index; i < n; ++i) {
            if ((i != index) && (arr[i-1] == arr[i]))
                continue;
            
            int element = arr[i];
            if (element > target) // Important optimisation
                break;
            
            v.push_back(element);
            f(i+1, (target-element), v, arr, ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        
        f(0, target, v, candidates, ans);
        
        return ans;
    }
};