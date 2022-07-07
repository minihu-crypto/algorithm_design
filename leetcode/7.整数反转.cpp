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
    int reverse(int x) {
        std::string str;
        str = std::to_string(x);
        if (x < 0) {
            std::string s1;
            s1.resize((str.size() - 1));
            for (int i = str.size() - 1; i > 0; --i) {
                s1[str.size() - i] = str[i];
            }
            long long result = atoll(s1.c_str());
            if (result <= pow(2, 31) - 1) {
                return result;
            } else {
                return 0;
            }
        } else {
            std::string s1;
            s1.resize(str.size());
            for (int i = str.size() - 1; i >= 0; --i) {
                s1[str.size() - i] = str[i];
            }
            long long result = atoll(s1.c_str());
            if (result >= -pow(2, 31)) {
                return result;
            } else {
                return 0;
            }
        }
    }
};

/* int main() {
    Solution solution;
    solution.reverse(123);
    return 0;
} */
// @lc code=end