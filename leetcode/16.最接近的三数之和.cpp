/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(target - sum);
        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                int diff = target - s;
                if (abs(diff) < minDiff) {
                    sum = s;
                    minDiff = abs(diff);
                }
                if (diff > 0) {
                    ++l;
                } else if (diff < 0) {
                    --r;
                } else {
                    return sum;
                }
            }
        }
        return sum;
    }
};
// @lc code=end
