/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <map>
using namespace std;
/*

 */
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2; ++i) {
            if (nums[i] > 0) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = size - 1;
            while (l < r) {
                if (nums[r] < 0) {
                    break;
                }
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> res(3);
                    res[0] = nums[i];
                    res[1] = nums[l];
                    res[2] = nums[r];
                    result.push_back(res);
                    ++l;
                    --r;
                } else if (sum < 0) {
                    ++l;
                } else {
                    --r;
                }
                while (l > i + 1 && nums[l] == nums[l - 1] && l < r) {
                    ++l;
                }
                while (r < size - 1 && nums[r] == nums[r + 1] && l < r) {
                    --r;
                }
            }
        }
        return result;
    }
};
// @lc code=end