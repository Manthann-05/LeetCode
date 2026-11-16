class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m && s[j] < g[i]) j++;
            if(j >= m) break;
            if(s[j]>=g[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};