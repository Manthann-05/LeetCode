class Solution {
public:
    long long countCommas(long long n) {
        long long temp = 1000;
        long long ans = 0;
        while(temp<=n){
            ans += n - temp + 1;
            
            if (temp > n / 1000)
                break;

            temp *= 1000;
        }
        return ans;
    }
};