class Solution {
public:
    int targetSum(vector<int>& nums, int target, int idx, int curr) {
        int n = nums.size();
        if (idx == n) {
            return curr == target ? 1 : 0;
        }
        int plus = targetSum(nums, target, idx + 1, curr + nums[idx]);
        int minus = targetSum(nums, target, idx + 1, curr - nums[idx]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetSum(nums, target, 0, 0);
    }
};