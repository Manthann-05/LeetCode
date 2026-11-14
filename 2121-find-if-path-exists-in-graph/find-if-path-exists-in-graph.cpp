
class Solution {
public:
    bool dfs(int node, vector<bool>& visited, vector<vector<int>>& chks, int destination) {
        if(node == destination) return true;
        visited[node] = true;
        for(int i = 0; i < chks[node].size(); i++) {
            int neighbor = chks[node][i];
            if(!visited[neighbor]) {
                if(dfs(neighbor, visited, chks, destination))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> chks(n);
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            chks[a].push_back(b);
            chks[b].push_back(a);
        }
        vector<bool> visited(n, false);
        return dfs(source, visited, chks, destination);
    }
};
