/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <cmath>
#include <iostream>
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int i = 1, j = 1;
        for (; pow(10, i) <= x; ++i) {  //找到最高位是几位数
        };
        while (i > j) {
            if ((x % static_cast<long long>(pow(10, i))) /
                    static_cast<int>(pow(10, i - 1)) !=
                (x % static_cast<long long>(pow(10, j))) /
                    static_cast<int>(pow(10, j - 1))) {
                return false;
            }
            --i;
            ++j;
        }
        return true;
    }
};
/* int main() {
    Solution solution;
    std::cout << solution.isPalindrome(1234567899);
    return 0;
} */
/* // @lc code=end */
