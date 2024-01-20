class Solution {
private:
    bool isPalindrome(string s, int l, int r) {
        int n = s.size();
        // int l = 0, r = n-1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void f(int index, vector<string> &v, string &s, vector<vector<string>> &ans) {
        int n = s.size();
        if (index >= n) {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < n; ++i) {
            // If current cut substring is palindrome, then add cut
            if (isPalindrome(s, index, i)) {
                v.push_back(s.substr(index, (i - index + 1))); // Add current substring to list
                f(i+1, v, s, ans);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        
        f(0, v, s, ans);
            
        return ans;
    }
};