/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include <vector>
#include <memory>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::shared_ptr;

// @lc code=start
class Solution {
public:
    vector<bool> visited;
    vector<bool> onPath;
    bool hasCycle;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>{});
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);
        hasCycle = false;
        
        for (const auto &item : prerequisites) {
            graph[item[1]].push_back(item[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            dfs(graph, i);
        }
        return !hasCycle;
    }
    
    void dfs(vector<vector<int>> &graph, int cur) {
        if (onPath[cur]) {
            hasCycle = true;
        }
        if (visited[cur] || hasCycle) return;
        
        visited[cur] = true;
        onPath[cur] = true;
        for (auto ch : graph[cur]) {
            dfs(graph, ch);
        }
        onPath[cur] = false;
    }
};
// @lc code=end

