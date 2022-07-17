/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
/*

 */
class Solution {
   public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
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
    };
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        auto size = nums.size();
        // 枚举第一个数，剩下两个数通过双指针来遍历(双指针前提是有序)
        sort(nums.begin(), nums.end());  //排序
        for (int i = 0; i < size - 2; ++i) {
            //剪枝1
            if (nums[i] > 0) {
                return result;
            }
            //去重1
            while (i > 0 && i < size && nums[i] == nums[i - 1]) {
                ++i;
            }
            //双指针
            size_t l = i + 1, r = size - 1;
            while (l < r) {
                //减枝2
                if (nums[r] < 0) {
                    return result;
                }
                auto sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    // 增大nums[l], 减小nums[r], 还有可能
                    ++l;
                    --r;
                } else if (sum < 0) {
                    //需要增大总和
                    ++l;
                } else {
                    --r;
                }
                //去重2
                while (l > i + 1 && l < r && nums[l] == nums[l - 1]) {
                    ++l;
                }
                while (r < size - 1 && l < r && nums[r] == nums[r + 1]) {
                    --r;
                }
            }
        }
        return result;
    }
};
/* int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> nums{0, 0, 0, 0};
    if (argc != 1) {
        for (int i = 1; i < argc; ++i) {
            nums.clear();
            nums.push_back(atoi(argv[i]));
        }
    }
    vector<vector<int>> result = solution.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
} */
// @lc code=end