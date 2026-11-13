
class Solution {
public:
    void dfs(int node, vector<int>& curr, vector<vector<int>>& graph, vector<vector<int>>& ans) {
        if(node == graph.size() - 1) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            curr.push_back(next);
            dfs(next, curr, graph, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(0);
        dfs(0, curr, graph, ans);
        return ans;
    }
};
