/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include <vector>
#include <queue>
using std::vector;
using std::queue;

// @lc code=start
class Solution {
public:
    vector<bool> visited;
    vector<bool> onPath;
    bool hasCycle;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);
        vector<vector<int>> graph(numCourses, vector<int>{});
        for (auto &item : prerequisites) {
            graph[item[1]].push_back(item[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            dfs(graph, i);
        } 
        if (hasCycle) return {};
        
        for (int i = 0; i < numCourses; ++i) visited[i] = false;
        for (int i = 0; i < numCourses; ++i) {
            traverse(graph, i);
        }
        return ans;
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
    void traverse(vector<vector<int>> &graph, int cur) {
        if (visited[cur]) return;

        queue<int> q;
        q.push(cur);
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            if (visited[c]) continue;
            visited[c] = true;
            ans.push_back(c);
            for (auto ch : graph[c]) {
                q.push(ch);
            }
        }
    }
};
// @lc code=end

