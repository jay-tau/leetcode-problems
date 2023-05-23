//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        long long ans = 0;
        int num_bits = 32;
        while (num_bits--) {
            // int bit = X % 2;
            ans <<= 1;
            ans += X % 2;
            X >>= 1;
            // ans = (2*ans) + bit;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends