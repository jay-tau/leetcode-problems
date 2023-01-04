class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        // Using count sort because 1<= heights[i] <= 100
        vector<int> counts(100+1, 0);
        
        for (int i = 0; i < n; i++) { // Create count
            counts[heights[i]] ++;
        }
        for (int i = 1; i < 101; i++) { // Apply prefix sum on count
            counts[i] += counts[i-1];
        }
        
        vector<int> expected(n);
        for (int i = 0; i < n; i++) { // Creating sorted array
            expected[counts[heights[i]]-1] = heights[i];
            counts[heights[i]]--;
        }
        // for (int i = 0; i < n; i++) { // Print sorted array
        //     cout << expected[i] << " ";
        // }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != expected[i])
                ans++;
        }
        return ans;
    }
};