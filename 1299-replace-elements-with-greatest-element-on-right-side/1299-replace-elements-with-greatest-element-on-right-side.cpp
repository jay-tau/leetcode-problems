class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        // Suffix array of maximum element
        vector<int> suffix(n);
        suffix[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = max(suffix[i+1], arr[i+1]);
        }
        suffix[n-1] = -1;
        return suffix;
    }
};