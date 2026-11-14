class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(matrix[i][j]==1) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};