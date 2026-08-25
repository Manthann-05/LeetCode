class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> s;
        for(auto& x:nums){
            if(x%k==0) s.insert(x);
        }
        int m = 1;
        while(s.find(k * m)!=s.end()) m++;
        return k * m;
    }
};