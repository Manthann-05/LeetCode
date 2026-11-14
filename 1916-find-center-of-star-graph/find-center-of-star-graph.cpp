class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> ans(n, 0);
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < 2; j++){
                int temp = edges[i][j];
                ans[temp-1]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(ans[i]==n-1) return i+1;
        }
        return 1;
    }
};