class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        
        int global_min = INT_MAX;
        
        for (size_t i = 1; i < strs.size(); i++) {
            string x = strs[i];
            int current_max = 0;
            // cout << x << " ";
            for (int j = 0; j < min(s.size(), x.size()); j++) {
                if (x[j] == s[j]) current_max++;
                else break;
            }
            // cout << i << " " << current_max << endl;
            global_min = min(global_min, current_max);
        }
        
        return s.substr(0, global_min);
    }
};