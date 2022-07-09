/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
class Solution {
   public:
    int reverse_v1(int x) {
        std::string str;
        str = std::to_string(x);
        if (x < 0) {
            str = str.substr(1);
            std::string s1;
            s1.resize(str.size());
            for (int i = str.size() - 1; i >= 0; --i) {
                s1[str.size() - i - 1] = str[i];
            }
            long long result = atoll(s1.c_str());
            if (result <= pow(2, 31) - 1) {
                return -result;
            } else {
                return 0;
            }
        } else {
            std::string s1;
            s1.resize(str.size());
            for (int i = str.size() - 1; i >= 0; --i) {
                s1[str.size() - 1 - i] = str[i];
            }
            long long result = atoll(s1.c_str());
            if (result <= pow(2, 31)) {
                return result;
            } else {
                return 0;
            }
        }
    }
};

/* int main() {
    Solution solution;
    int a = solution.reverse(1534236469);
    return 0;
} */
// @lc code=end