class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = 0;
            while(nums[i]>0){
                int rem = nums[i]%10;
                sum+=rem;
                nums[i]/=10;
            }
            if(sum == i) ans = min(ans,sum);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};