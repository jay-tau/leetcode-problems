class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        
        string ans;
        
        for (char c: s) {
            if (st.empty()) {
                st.push('(');
                continue;
            }
            char x = st.top();
            if (x == c) {
                st.push('(');
                ans += '(';
            }
            else {
                st.pop();
                if (st.empty())
                    continue;
                ans += ')';
            }
        }
        
        return ans;
    }
};