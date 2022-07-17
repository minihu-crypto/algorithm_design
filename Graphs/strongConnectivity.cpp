#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
    有向图的强连通性测试
        利用性质：如果点u和v强连通，v和w强连通，那么u和w强连通
        1. 从点 s 出发，测试 s 到所有节点的连通性
        2. 构造反向图，测试所有节点到s的连通性
        如果s和所有节点互联通，则该图强连通
 */

class Vertical {
   public:
    Vertical(int f, int t, int v) : from(f), to(t), value(v){};
    int from, to, value;
};
vector<vector<Vertical>> graph;

bool bfsSearch(vector<vector<Vertical>>& graph, unsigned s, unsigned t) {
    vector<bool> Discovered(graph.size(), false);
    Discovered[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto vertical : graph[cur]) {
            if (!Discovered[vertical.to]) {
                //在这里访问吧
                // ...
                if (vertical.to == t) {
                    //找到目标
                    return true;
                }
                q.push(vertical.to);
                Discovered[vertical.to] = true;
            }
        }
    }
    return false;
}

bool connectivityTest(vector<vector<Vertical>>& graph, unsigned s, unsigned t) {
    return bfsSearch(graph, s, t) && bfsSearch(graph, t, s);
}

vector<vector<Vertical>> reverseGraph(vector<vector<Vertical>>& graph) {
    vector<vector<Vertical>> rvGraph(graph.size());
    for (auto list : graph) {
        for (auto vertical : list) {
            rvGraph[vertical.to].push_back(
                Vertical(vertical.to, vertical.from, vertical.value));
        }
    }
    return rvGraph;
}

bool connectivityTestAllNodes(vector<vector<Vertical>>& graph, unsigned s) {
    vector<bool> Discovered(graph.size(), false);
    Discovered[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto vertical : graph[cur]) {
            if (Discovered[vertical.to]) {
                continue;
            }
            //访问目标节点 vertical.to
            Discovered[vertical.to] = true;
            q.push(vertical.to);
        }
    }
    for (auto discovered : Discovered) {
        if (!discovered) {
            return false;
        }
    }
    return true;
}

bool strongConnectivityTest(vector<vector<Vertical>>& graph) {
    if (!connectivityTestAllNodes(graph, 0)) {
        return false;
    };
    vector<vector<Vertical>> rvGraph = reverseGraph(graph);
    for (int i = 1; i < graph.size(); ++i) {
        if (!bfsSearch(rvGraph, i, 0)) {
            return false;
        }
    }
    return true;
}