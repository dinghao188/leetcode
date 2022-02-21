/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<bool> visited;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); ++i) visited.push_back(false);
        
        vector<vector<int>> ans;
        dfs(graph, 0, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>> &graph, int cur_node, vector<vector<int>> &ans) {
        if (visited[cur_node]) return;

        path.push_back(cur_node);
        visited[cur_node] = true;
        if (cur_node != graph.size() - 1) {
            for (auto next_node : graph[cur_node]) {
                dfs(graph, next_node, ans);
            }
        } else {
            ans.push_back(path);
        }
        path.pop_back();
        visited[cur_node] = false;
    }
};
// @lc code=end

