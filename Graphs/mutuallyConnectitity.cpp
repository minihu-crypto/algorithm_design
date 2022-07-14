#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
    有向图的互连通性
        起始点和终止点互换，进行两次搜索
 */

class Vertical {
   public:
    int from, to, value;
};
vector<vector<Vertical>> graph;

bool bfsSearch(vector<vector<Vertical>>& graph, unsigned s, unsigned t) {
    vector<bool> Discovered(graph.size(), false);
    // 处理 s
    Discovered[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur == t) {
            return true;
        }
        for (auto vertical : graph[cur]) {
            if (!Discovered[vertical.to]) {
                q.push(vertical.to);
                Discovered[vertical.to] = true;
            }
        }
    }
    return false;
}
bool testConnectivity(vector<vector<Vertical>>& graph, unsigned s, unsigned t) {
    return bfsSearch(graph, s, t) && bfsSearch(graph, t, s);
}