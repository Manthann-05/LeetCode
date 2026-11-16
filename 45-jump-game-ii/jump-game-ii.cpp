class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> chk(n, 0);
        for(int i = 0; i < n; i++) {
            int reach = i + nums[i];

            for(int j = i + 1; j <= min(reach, n-1); j++) {
                if(chk[j]!=0) chk[j] = min(chk[j],chk[i]+1);
                else chk[j] += chk[i] + 1;
            }
        }
        return chk[n-1];
    }
};