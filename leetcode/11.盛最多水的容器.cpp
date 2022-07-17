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
        例如[1,8,6,2,5,4,8,3,7]的初始状态:i=0,j=8,高度分别为1和7
        1. 此时的高度瓶颈在i=0,高度为1,若移动右指针,永远不可能将面积变得更大
            移动左指针才有可能得到更大的解
            若移动右指针，高度瓶颈在height[i],而长度变短，不可能得到更优
        2. 若两边高度相等, 随便移动一边即可
 */
#include <cmath>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxArea(vector<int>& height) {
        unsigned i = 0, j = height.size() - 1;
        int res = min(height[i], height[j]) * (j - i);
        while (i != j) {
            res =
                max(res, static_cast<int>(min(height[i], height[j]) * (j - i)));
            if (height[i] <= height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return res;
    }
};
// @lc code=end
