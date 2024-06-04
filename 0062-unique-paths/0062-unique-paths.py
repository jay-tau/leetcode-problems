class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #if (m < n) swap(m, n);
        # long long ans = 1;
        
        # for (int i = (m-1 + n-1); i > (m-1); i--) ans *= i;
        
        # for (int i = (n - 1); i >= 1; i--) ans /= i;
        
        # return (int) ans;
    
        if m < n:
            _ = m
            m = n
            n = _
        
        if n == 1:
            return 1
        
        product = lambda x, y: x * y
        return reduce(product, (x for x in range(m - 1 + n - 1, m - 1, -1))) // factorial(n-1)
        
        