/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto result = nums[0] + nums[1] + nums[2];
        auto size = nums.size();
        // 遍历第一个数，剩余两个数用双指针(先排序)
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < size - 2; ++i) {
            size_t l = i + 1, r = size - 1;
            auto sum = nums[i] + nums[l] + nums[r];
            while (l < r) {
                if (abs(target - sum) < abs(target - result)) {
                    //总和更接近
                    result = sum;
                }
                if (sum < target) {
                    sum -= nums[l];
                    ++l;
                    if (l > r) {
                        break;
                    }
                    sum += nums[l];
                } else if (sum > target) {
                    sum -= nums[r];
                    --r;
                    if (l > r) {
                        break;
                    }
                    sum += nums[r];
                } else {
                    //相等
                    return target;
                }
            }
        }
        return result;
    }
    int threeSumClosest1(vector<int>& nums, int target) {
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
