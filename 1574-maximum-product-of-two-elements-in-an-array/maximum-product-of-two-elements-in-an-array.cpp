class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }

        int first = pq.top() - 1;
        pq.pop();
        return first * (pq.top() - 1);
    }
};