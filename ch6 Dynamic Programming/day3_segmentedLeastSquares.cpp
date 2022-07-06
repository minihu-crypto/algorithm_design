#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    子问题数量为 poly(n) 的动态规划问题
    问题描述：给定一个坐标轴上的n个点，按连续分段的方式，通过多条直线进行拟合，求总损失最小的分段方法
        损失包括：1.每条直线带来C的损失；2.每段内通过算leastsquare得到段内损失。
            总损失为1和2求和
        递推公式：OPT(j) = min(e[i][j]+C+OPT(i-1))
            其中,i<j,i和j为其中分出的一段的两边界,e[i][j]为该段的段内leastsqure损失
 */

class point {
   public:
    double x = 0.0, y = 0.0;
    point(const double& x, const double& y) {
        this->x = x;
        this->y = y;
    }
    bool operator<(const point& p) { return this->x < p.x; }
};

class Solution {
   public:
    double segmentedLeastSquares(vector<point>& points, const int& C) {
        int size = points.size();
        // 1.先对point进行排序
        sort(points.begin(), points.end());
        // 2.算出e[i][j]
        vector<vector<double>> e(size, vector<double>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                e[i][j] = leastSquares(points, i, j);
            }
        }
        // 3.dp核心 Opt数组
        vector<double> Opt(size, 0.0);
        Opt[0] = C;  //第一个点，单个点损失为C
        for (int i = 1; i < size; ++i) {
            // minErr初始化为单点分段损失
            Opt[i] = Opt[i - 1] + C;
            for (int j = i - 1; j >= 0; --j) {
                Opt[i] = min(Opt[i], Opt[j] + C + e[j][i]);
            }
        }
        return Opt[size - 1];
    };
    double leastSquares(const vector<point>& points, const int i, const int j) {
        if (i == j) {
            return 0.0;
        }
        //算出所有it_i到it_j之间的点的损失
        int n = j - i + 1;
        // 1.x_sum
        double x_sum = 0.0;
        for (int k = i; k <= j; ++k) {
            x_sum += points[k].x;
        }
        // 2.x^2_sum
        double x_2_sum = 0.0;
        for (int k = i; k <= j; ++k) {
            x_2_sum += pow(points[k].x, 2);
        }
        // 3.x_y_sum
        double x_y_sum = 0.0;
        for (int k = i; k <= j; ++k) {
            x_y_sum += points[k].x * points[k].y;
        }
        // 4.y_sum
        double y_sum = 0.0;
        for (int k = i; k <= j; ++k) {
            y_sum += points[k].y;
        }
        // 5.a
        double a =
            (n * x_y_sum - x_sum * y_sum) / (n * x_2_sum - pow(x_sum, 2));
        // 6.b
        double b = (y_sum - a * x_sum) / (n);
        // 7.Error
        double err = 0.0;
        for (int k = i; k <= j; ++k) {
            err += pow(points[k].y - a * points[k].x - b, 2);
        }
        return err;
    }
};

int main(int argc, char* argv[]) {
    string programName(argv[0]);
    string in_str = programName + "In.txt", out_str = programName + "Out.txt";
    const char* IN_FILE = in_str.c_str();
    const char* OUT_FILE = out_str.c_str();
    freopen(IN_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    vector<point> points;
    int C;
    Solution solution;
    cout << "最小误差为: " << solution.segmentedLeastSquares(points, C) << endl;
    return 0;
}