#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1 && !dfs(graph, visited, i, 0)) {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& visited, int node, int depth) {
        visited[node] = depth;

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == -1) {
                if (!dfs(graph, visited, neighbor, depth + 1)) {
                    return false;
                }
            } else if ((visited[node] - visited[neighbor]) % 2 == 0) {
                return false;
            }
        }

        return true;
    }
};