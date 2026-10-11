class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int temp = i + 1;
            if(n % temp == 0) sum += nums[i]*nums[i];
        }
        return sum;
    }
};