class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        set<char> st;
        while(r<n){
            if(st.find(s[r])!=st.end()){
                while(s[l]!=s[r]){
                    st.erase(s[l]);
                    l++;
                }
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};