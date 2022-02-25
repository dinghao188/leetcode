/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
    vector<bool> visited;
    vector<bool> part;
    bool binarable;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        visited = part = vector<bool>(n, false);
        binarable = true;

        vector<vector<int>> graph(n, vector<int>{});
        for (auto &item : dislikes) {
            graph[item[0]-1].push_back(item[1]-1);
            graph[item[1]-1].push_back(item[0]-1);
        }
        
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            
            visited[i] = true;
            dfs(graph, i);
        }
        
        return binarable;
    }
    
    void dfs(vector<vector<int>> &graph, int cur) {
        if (!binarable) return;
        
        for (auto next : graph[cur]) {
            if (visited[next]) {
                if (part[cur] == part[next]) {
                    binarable = false;
                    return;
                }
                continue;
            }
            
            visited[next] = true;
            part[next] = !part[cur];
            dfs(graph, next);
        }
    }
};
// @lc code=end

