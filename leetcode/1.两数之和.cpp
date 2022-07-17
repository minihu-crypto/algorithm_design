/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int find = target - nums[i];
            auto it = mp.find(find);
            if (it == mp.end()) {
                // 没找到
                mp[nums[i]] = i;
            } else {
                result.push_back(it->second);
                result.push_back(i);
            }
        }
        return result;
    }
};
// @lc code=end
