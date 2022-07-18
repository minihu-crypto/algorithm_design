/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <utility>
using namespace std;
/*
    通过unordered_set来进行唯一性检测
    尽量利用已有的信息
    利用左右双指针来滑动窗口
 */
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int result = 1;
        unordered_map<char, int> mp;
        int l = 0, r = 1;
        mp.insert(std::pair<char, int>(s[l], l));
        while (r < s.size()) {
            if (s.size() - l <= result) {
                //剪枝
                return result;
            }
            while (r < s.size() && mp.find(s[r]) == mp.end()) {
                //不重复
                mp.insert(std::pair<char, int>(s[r], r));
                ++r;
            }
            result = max(result, r - l);  //更新result
            //临界情况
            if (r == s.size()) {
                return result;
            }
            int idx = mp[s[r]];
            for (int i = l; i <= idx; ++i) {  //从map里删除
                mp.erase(s[i]);
            }
            l = idx + 1;  // r这个位置重复了,根据它找起始位置
        }
        return result;
    }
};
/* int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    return 0;
} */
// @lc code=end
