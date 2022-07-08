/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
class Solution {
   public:
    pair<int, int> expandAroundCentet(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {++left, --right};
    }
    string longestPalindrome(string s) {
        auto size = s.size();
        if (size <= 1) {
            return s;
        }
        // 边界扩展
        int start = 0, end = 0;
        for (int i = 0; i < size; ++i) {
            int left1, right1;
            std::tie(left1, right1) = expandAroundCentet(s, i, i);
            auto [left2, right2] = expandAroundCentet(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    string longestPalindrome_dp(string s) {
        auto size = s.size();
        if (size == 0 || size == 1) {
            return s;
        }
        vector<vector<bool>> dp(
            size + 1,
            vector<bool>(size,
                         true));  // dp数组两个下标分别为长度及起始位置
        // 1. dp迭代外层循环为子串长度
        // 2. 长度为2单独计算
        int start = 0, len = 1;
        for (int j = 0; j < size - 1; ++j) {
            if (s[j] == s[j + 1]) {
                dp[2][j] = true;
                len = 2;
                start = j;
            } else {
                dp[2][j] = false;
            }
        }
        for (int i = 3; i <= size; ++i) {  //长度下标从3开始，长度0和1默认为true
            for (int j = 0; j < size - i + 1; ++j) {  //起始下标从0开始
                if (true == dp[i - 2][j + 1] && s[j] == s[j + i - 1]) {
                    //当前为回文
                    if (i > len) {
                        len = i;
                        start = j;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(start, len);
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome_dp("aacabdkacaa") << endl;
    return 0;
}
// @lc code=end
