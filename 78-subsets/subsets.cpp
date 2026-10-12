
class Solution {
public:
    void allSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        allSubsets(nums, ans, curr, idx + 1);
        curr.pop_back();
        allSubsets(nums, ans, curr, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        allSubsets(nums, ans, curr, 0);
        return ans;
    }
};
