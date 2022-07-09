/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <cstdint>
#include <string>
using namespace std;

/*
    回顾的时候学习一下自动机写法
 */

class Solution {
   public:
    int myAtoi(string s) {
        // 1.删除前导空格
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] != ' ') {
                if (i < s.size()) {
                    s = s.substr(i);
                }
                break;
            }
        }
        // s.erase(0, s.find_first_not_of(' '));
        //  2.特殊情况
        if (s.size() == 0) {
            return 0;
        }
        if (s[0] != '+' && s[0] != '-' && !(s[0] <= '9' && s[0] >= '0')) {
            //第一个字符既不是符号，也不是数字
            return 0;
        }
        // 3.处理符号
        bool neg = s[0] == '-';
        // 4.迭代处理并实时计算是否溢出
        long long ans = 0;
        long long max = static_cast<long long>(INT32_MAX);
        long long min = static_cast<long long>(INT32_MIN);
        int i = (s[0] == '+' || s[0] == '-') ? 1 : 0;  //有符号则进位
        while (i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
            ans = ans * 10 + (s[i] - '0');
            if (neg && -ans <= min) {
                return INT32_MIN;
            }
            if (!neg && ans >= max) {
                return INT32_MAX;
            }
            ++i;
        }
        if (neg) {
            return -ans;
        }
        return ans;
    }
};

/* int main() {
    Solution solution;
    solution.myAtoi("42");
    return 0;
} */
// @lc code=end
