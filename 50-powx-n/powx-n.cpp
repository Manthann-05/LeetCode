class Solution {
public:

    double recursion(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        double temp = recursion(x, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        }
        return x * temp * temp;
    }

    double myPow(double x, int n) {
        long long N = llabs((long long)n);
        double ans = recursion(x, N);
        return n < 0 ? 1 / ans : ans;
    }
};