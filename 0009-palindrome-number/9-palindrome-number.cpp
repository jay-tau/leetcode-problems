class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int front_divider = 1, x_copy = x/10;
        while (x_copy > 0) {
            front_divider *= 10;
            x_copy /= 10;
        }
        
        cout << front_divider << endl;
        
        while (x > 0) {
            int front_digit = x/front_divider;
            int back_digit = x%10;
            
            if (front_digit != back_digit)
                return false;

            x %= front_divider; // Remove front digit
            x /= 10; // Remove back digit
            front_divider /= 100;
        }
        return true;
    }
};