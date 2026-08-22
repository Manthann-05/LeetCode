class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, mul = 1;
        int temp = n;
        while(temp>0){
            int rem = temp%10;
            sum += rem;
            mul *= rem;
            temp /= 10;
        }
        if(n % (sum + mul) == 0) return true;
        return false;
    }
};