
class Solution {
public:
    int solve(vector<int>& nums, int idx, int currXor) {
        if (idx == nums.size()) {
            return currXor;
        }
        int include = solve(nums, idx + 1, currXor ^ nums[idx]);
        int exclude = solve(nums, idx + 1, currXor);
        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};
