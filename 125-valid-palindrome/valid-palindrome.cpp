class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || 
               (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            }
        }

        int l = 0, r = ans.size() - 1;

        while(l < r) {
            if(ans[l] != ans[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};