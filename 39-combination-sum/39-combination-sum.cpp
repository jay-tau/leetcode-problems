class Solution {
private:
    void f(int index, int target, vector<int> &v, vector<int> &arr, vector<vector<int>> &ans) {
        int n = arr.size();
        if ((index > n) || (target < 0)) { // Impossible
            cout << "ERROR" << endl;
            return;
        }
        if (index == n) {
            if (target == 0)
                ans.push_back(v);
            return;
        }
        
        if (arr[index] <= target) {
            v.push_back(arr[index]);
            f(index, target-arr[index], v, arr, ans); // Same index can be taken again
            v.pop_back();
        }
        f(index+1, target, v, arr, ans); // Do not take. Skip to next element
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        f(0, target, v, candidates, ans);
        
        return ans;
    }
};