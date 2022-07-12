#include <cstddef>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/*
    图的邻接表表示
 */
class Vertical {
   public:
    int s, t, d;
};

/*
    从 s 出发,找到所有联通的点,返回discovered数组(或一个二维的list，按层来存储)
 */

vector<bool> bfs(vector<list<Vertical>>& graph, int s, int t) {
    int n = graph.size();
    vector<bool> discovered(n, false);
    discovered[s] = true;
    queue<int> q;
    q.push(s);
    // 如果想要统计每个节点的深度
    vector<int> depths(n);
    depths[s] = 0;
    while (!q.empty()) {
        int cur = q.back();
        q.pop();
        for (auto vertical : graph[cur]) {
            if (!discovered[vertical.t]) {
                q.push(vertical.t);
                // visit
                discovered[vertical.t] = true;
                depths[vertical.t] = depths[vertical.s] + 1;
            }
        }
    }
    return discovered;
}

void dfs(vector<list<Vertical>>& graph, int cur, int t) {
    static vector<bool> discovered(graph.size(), false);
    if (discovered[t]) {
        return;
    }
    // visit cur
    discovered[cur] = true;
    //向下递归
    for (auto vertical : graph[cur]) {
        if (!discovered[vertical.t]) {
            dfs(graph, vertical.t, t);
        }
    }
}

vector<bool> dfs_iterator(vector<list<Vertical>>& graph, int s, int t) {
    // 这里采用访问时discovered[i]=true的策略，与上面bfs对照
    vector<bool> discovered(graph.size(), false);
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        // 访问cur
        if (discovered[cur]) {
            //需要一个额外的判断，因为节点可能会重复入栈
            continue;
        }
        discovered[cur] = true;
        for (auto vertical : graph[cur]) {
            if (!discovered[vertical.t]) {
                st.push(vertical.t);
            }
        }
    }
    return discovered;
}

int main() {
    int s, t, d;
    cin >> s >> t >> d;

    vector<list<Vertical>> graph(10);
    bfs(graph, 0, 9);

    dfs(graph, 0, 9);

    dfs_iterator(graph, 0, 9);

    return 0;
}