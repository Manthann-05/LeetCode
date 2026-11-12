class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected){
        int n = isConnected.size();
        visited[node] = true;

        for(int i = 0; i < n; i++){
            if(visited[i]==false && isConnected[node][i]==1){
                dfs(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(visited[i]==false){
                ans++;
                dfs(i, visited, isConnected);
            }
        }
        return ans;
    }
};