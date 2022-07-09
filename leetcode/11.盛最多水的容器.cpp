/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

/*
    通过双指针求解：
        取 i=0  取 j=height.size()-1
        每次移动一个指针（下标对应height更小的一个）
    正确性证明：
        例如[1,8,6,2,5,4,8,3,7]的初始状态:i=0,j=8
        移动左指针才有可能得到更大的解
            若移动右指针，高度瓶颈在height[i],而长度变短，不可能得到更优
 */
#include <cmath>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxArea(vector<int>& height) {
        unsigned i = 0, j = height.size() - 1;
        unsigned ans = 0;
        while (i != j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};
// @lc code=end
