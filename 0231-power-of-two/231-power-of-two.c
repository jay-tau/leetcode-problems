

bool isPowerOfTwo(int n) {
    if (n == 1) {
        return true;
    }
    else if ((n <= 0) || (n % 2 != 0)) {
        return false;
    }
    int count, rem; count = 0;
    while (n > 0) {
        rem = n % 2;
        if (rem == 1) {
            count++;
        }
        if (count > 1) {
            return false;
        }
         n /= 2;
    }
    return true;
}