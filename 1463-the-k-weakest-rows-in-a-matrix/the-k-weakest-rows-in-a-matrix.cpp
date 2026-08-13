class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int,int>> ans;

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) count++;
            }
            ans.push_back({count,i});
        }

        sort(ans.begin(),ans.end());
        vector<int> res;

        for(int i = 0; i < k; i++) res.push_back(ans[i].second);

        return res;
    }
};