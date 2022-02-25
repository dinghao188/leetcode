#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <gtest/gtest.h>
using namespace std;

//并查集,可以用来判断图的连通性
class UnionFindSet {
public:
    UnionFindSet(int n) {
        count = n;
        size = parent = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    
    bool Connected(int p, int q) {
        int rootP = Find(p);
        int rootQ = Find(q);
        return rootP == rootQ;
    }
    
    void Union(int p, int q) {
        int rootP = Find(p);
        int rootQ = Find(q);
        if (rootP == rootQ) return;
        
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        --count;
    }
    
    int Count() { return count; }
private:
    int Find(int p) {
        while (parent[p] != p) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
private:
    vector<int> parent;
    vector<int> size;
    int count;
};

struct Edge {
    int end_point_a;
    int end_point_b;
    int weight;
};
//Kruskal最小生成树算法,边比较少时使用
int KruskalMST(vector<Edge> &edges, int n) {
    UnionFindSet ufs(n);
    auto cmp = [](const Edge &e1, const Edge &e2) {
        return e1.weight < e2.weight;
    };
    sort(edges.begin(), edges.end(), cmp);
    
    int ans = 0;
    for (auto &edge : edges) {
        if (ufs.Connected(edge.end_point_a, edge.end_point_b)) continue;
        ufs.Union(edge.end_point_a, edge.end_point_b);
        ans += edge.weight;
    }
    
    if (ufs.Count() == 1) return ans;
    else return 0;
}
//Prim最小生成树算法，图比较稠密时使用
int PrimMST(vector<vector<int>> &graph) {
    unordered_set<int> visited; 
    unordered_set<int> un_visited;
    
    visited.insert(0);
    for (int i = 1; i < graph.size(); ++i) un_visited.insert(i);
    
    auto cmp = [](const Edge &e1, const Edge &e2) { return e1.weight > e2.weight; };
    
    int cur = 0;
    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[cur][i] == -1) continue;
        pq.push({cur, i, graph[cur][i]});
    }

    int ans = 0;
    while (visited.size() != graph.size()) {
        auto e = pq.top(); pq.pop();
        cur = e.end_point_b;
        if (visited.count(cur) != 0) continue;
        
        visited.insert(cur);
        un_visited.erase(cur);
        ans += e.weight;
        for (int i = 0; i < graph.size(); ++i) {
            if (visited.count(i) > 0 || graph[cur][i] == -1) continue;
            pq.push({cur, i, graph[cur][i]});
        } 
    }
    
    return ans;
}

TEST(graph, UnionFindSet) {
    UnionFindSet ufs(20);
    ufs.Union(0, 1);
    ufs.Union(2, 3);
    EXPECT_EQ(ufs.Connected(0, 1), true);
    EXPECT_EQ(ufs.Connected(0, 2), false);
    ufs.Union(1, 3);
    EXPECT_EQ(ufs.Connected(0, 2), true);
}

TEST(graph, KruskalMST) {
    vector<Edge> edges = {{0,1,1}, {0,2,2}, {1,2,3}, {2,4,5}, {3,6,2}, {3,5,1}, {2,3,10}};
    EXPECT_EQ(KruskalMST(edges, 7), 21);
}

TEST(graph, PrimMST) {
    vector<vector<int>> graph = {
        {-1, 1, 2, -1, -1, -1, -1},
        {-1, -1, 3, -1, -1, -1, -1},
        {-1, -1, -1, 10, 5, -1, -1},
        {-1, -1, -1, -1, -1, 1, 2},
        {-1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1},
    };
    EXPECT_EQ(PrimMST(graph), 21);
}