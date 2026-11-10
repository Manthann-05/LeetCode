class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        
        for (int i = 0; i < nums.size(); i++) {
            if(min_heap.size() < k){
                min_heap.push(nums[i]);
            }
            else if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};