class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int mx = 1, mn = 1;
        for(int i = 1; i < n; i++){ 
            if(nums[i]>nums[i-1]){
                mn = 1;
                mx++;
            }
            else if(nums[i] < nums[i-1]){
                mx = 1;
                mn++;
            }
            else{
                mx = 1;
                mn = 1;
            }
            maxLen = max(max(mx,maxLen),mn);
        }
        return maxLen;
    }
};