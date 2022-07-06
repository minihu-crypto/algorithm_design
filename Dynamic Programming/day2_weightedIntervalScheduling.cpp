#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    带权重的活动安排，目标是获得最大的加权价值
 */

class interval {
   public:
    int s, f, v;
    bool operator<(const interval& i) { return this->f < i.f; }
};

class Solution {
   public:
    int weightedIntervalScheduling(vector<interval>& intervals) {
        auto size = intervals.size();
        // 1.依照结束时间，对intervals进行排序
        sort(intervals.begin(), intervals.end());
        // 2.算出每个活动i开始之前，最晚结束的活动p[i]
        vector<int> p(
            size,
            -1);  //初始化为-1，p[0]=-1，后续如果有p[i]=-1，则没有满足条件的前置活动
        for (int i = 1; i < size; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (intervals[j].f <= intervals[i].s) {
                    p[i] = j;
                    break;
                }
            }
        }
        // 3.dp算法，递推方程为：
        vector<int> Opt(size, 0);
        Opt[0] = intervals[0].v;
        for (int i = 1; i < size; ++i) {
            if (p[i] == -1) {
                //该活动没有前置活动
                Opt[i] = max(Opt[i - 1], intervals[i].v);
            } else {
                Opt[i] = max(Opt[i - 1], Opt[p[i]] + intervals[i].v);
            }
        }
        return Opt[size - 1];
    }
};

int main(int argc, char* argv[]) {
    string programName(argv[0]);
    string in_str = programName + "In.txt", out_str = programName + "Out.txt";
    const char* IN_FILE = in_str.c_str();
    const char* OUT_FILE = out_str.c_str();
    freopen(IN_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    return 0;
}