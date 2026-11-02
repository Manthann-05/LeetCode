class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0, len = 0;
        map<char,int> mpp;
        int l = 0;
        for(int i = 0; i < n; i++) {
            while(mpp[s[i]] > 0) {
                mpp[s[l]]--;
                l++;
                len--;
            }
            mpp[s[i]]++;
            len++;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};