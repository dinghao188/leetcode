/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */
#include <vector>
#include <queue>
using std::vector;
using std::queue;

// @lc code=start
class Solution {
public:
    vector<bool> visited;
    vector<bool> part;

    bool isBipartite(vector<vector<int>>& graph) {
        part = visited = vector<bool>(graph.size(), false);        
        
        queue<int> q;
        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i); 
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                
                for (auto next : graph[cur]) {
                    if (visited[next] && part[cur] == part[next]) return false;
                    if (visited[next]) continue;
                    
                    visited[next] = true;
                    part[next] = !part[cur];
                    q.push(next);
                }
            }
        } 
        return true;
    }
};
// @lc code=end

