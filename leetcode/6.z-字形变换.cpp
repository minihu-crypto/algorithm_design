/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result = "";
        int mod = numRows * 2 - 2;
        //第一行
        for (int i = 0; i < s.size(); i += mod) {
            result.push_back(s[i]);
        }
        //中间行
        for (int line = 1; line < numRows - 1; ++line) {
            for (int i = line; i < s.size(); i += mod) {
                result.push_back(s[i]);
                if ((i + mod - 2 * (i % mod)) < s.size()) {
                    result.push_back(s[i + mod - 2 * (i % mod)]);
                }
            }
        }
        //最后一行
        for (int i = numRows - 1; i < s.size(); i += mod) {
            result.push_back(s[i]);
        }
        return result;
    }
    string convert_buffer(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> vec(numRows, "");
        int mod = 2 * numRows - 2;
        for (int i = 0; i < s.size(); ++i) {
            if ((i % mod) < numRows) {
                vec[i % mod].push_back(s[i]);
            } else {
                vec[numRows - 2 - (i % mod) % numRows].push_back(s[i]);
            }
        }
        string result = "";
        for (int i = 0; i < numRows; ++i) {
            result += vec[i];
        }
        return result;
    }
};

/* int main(){
    Solution solution;
    solution.convert("PAYPALISHIRING", 3);
    return 0;
} */
// @lc code=end
