class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> chk(n, 0);
        chk[0] = 1;

        for(int i = 0; i < n; i++) {

            if(chk[i] == 0) continue;

            int reach = i + nums[i];

            for(int j = i + 1; j <= min(reach, n-1); j++) {
                chk[j] = 1;
            }
        }

        return chk[n-1] == 1;
    }
};