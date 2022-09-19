class Solution {
public:
    bool isPalindrome(string s) {
        // 2 pointer problem. O(n)
        int left = 0, right = s.length()-1;
        while (left < right) {
            char head = s[left], tail = s[right];
            if (!isalnum(head)) {
                left++;
                continue;
            }
            if (!isalnum(tail)) {
                right--;
                continue;
            }
            head = tolower(head); tail = tolower(tail);
            if (head != tail) {
                cout << head << " " << tail << endl;
                return false;
            }
            left++; right--;
        }
        return true;
    }
};