class Solution {
public:
    int Fibonacci(int n) {
        int tmp[2] = {0, 1};
        if (n < 2) return tmp[n];
        int i = 0;
        while (i <= n-2) {
            tmp[i%2] = tmp[0] + tmp[1];
            ++i;
        }
        return tmp[n%2];
    }
};