/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
/*
    采用dp来做
        假设s的size为m,p的size为n
        1. s[m-1]==p[n-1]||p[n-1]=='.'，则dp[m][n]=dp[m-1][n-1]
        2. p[n-1]=="*"，s往前迭代，到一样的字符的第一个(假设下标为t)
            dp[m-1][n-1]=dp[t][n-2]
        3. 从前往后怎么循环呢？
 */
class Solution {
   public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size(), vector<bool>(p.size()));
        
    }
};
// @lc code=end
