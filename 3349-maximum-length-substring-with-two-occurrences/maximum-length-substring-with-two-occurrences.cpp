class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int len = 0, maxLen = 0;
        map<char, int> mpp;
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (mpp[s[i]] == 2) {
                while (s[l] != s[i]) {
                    mpp[s[l]]--;
                    l++;
                }
                mpp[s[l]]--;
                l++;
            }
            mpp[s[i]]++;
            len = i - l + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};