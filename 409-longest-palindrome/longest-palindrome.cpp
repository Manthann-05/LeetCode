class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        map<char, int> mpp;
        for(auto &x: s){
            mpp[x]++;
        }

        int len = 0;
        bool odd = false;
        for (auto &x : mpp) {
            len += (x.second / 2) * 2;
            if (x.second % 2 == 1) {
                odd = true;
            }
        }
        if (odd) len++;
        return len;
    }
};