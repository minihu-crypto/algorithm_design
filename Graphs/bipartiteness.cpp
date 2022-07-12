#include <list>
#include <queue>
#include <vector>
using namespace std;

/*
    二分图定义：点集V可以被分为两部分 X 和 Y, 且所有边连接的两点分属两个点集
    通过bfs遍历所有点，并对点进行染色，达成二分图测试
 */

const int RED = 1;
const int BLUE = 2;

// 定义边
class Vertical {
   public:
    int idx, value, t;
};
// 图的邻接表存储
vector<list<Vertical>> graph;

int oppositeColor(int color) {
    if (color == RED) return BLUE;
    return RED;
}
bool bipartitenessTestBFS(vector<list<Vertical>>& graph, int s = 0) {
    // 默认从下标为0开始,colors可以替代discovered数组
    vector<bool> colors(graph.size(), 0);
    colors[s] = RED;
    // bfs queue
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.back();
        q.pop();
        for (auto vertical : graph[cur]) {
            if (!colors[vertical.t]) {
                //下一个点还未染色
                colors[vertical.t] = oppositeColor(colors[cur]);
                // 将下一个点放入queue
                q.push(vertical.t);
            } else if (colors[vertical.t] == colors[cur]) {
                // 如果下一个点与当前点颜色一致
                return false;
            }
        }
    }
    return true;
}