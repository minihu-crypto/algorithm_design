/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

/*
    要求复杂度为 log(m+n)，肯定需要二分搜索，不能直接合并数组
    当(m+n)为奇数时，需要找到第(m+n)/2+1大的数
    当(m+n)为偶数时，需要找到第(m+n)/2,(m+n)/2+1大的数，求平均

    * 上述问题可以转化为求两个有序数组中第k小的数的问题
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 != 0) {
            return findKth(nums1, nums2, (m + n) / 2 + 1);
        } else {
            return (findKth(nums1, nums2, (m + n) / 2) +
                    findKth(nums1, nums2, (m + n) / 2 + 1)) /
                   2.0;
        }
    }
    double findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        /*
            找两个有序数组第k个数,想办法二分减治! 每次最多剔除K/2个数
            剔除方法,递进两个数组的起始下标 l1, l2
         */
        int l1 = 0, l2 = 0;
        int m = nums1.size(), n = nums2.size();
        while (1) {
            //边界情况1, 只剩一个数组
            if (l1 >= m) {
                return nums2[l2 + k - 1];
            }
            if (l2 >= n) {
                return nums1[l1 + k - 1];
            }
            //边界情况2,剩下2个数组且k==1
            if (k == 1) {
                return min(nums1[l1], nums2[l2]);
            }

            //一般情况, 两数组中剔除
            int idx1 = min(m - 1, l1 + k / 2 - 1);  //从数组中最多剔除数量有限
            int idx2 = min(n - 1, l2 + k / 2 - 1);
            if (nums1[idx1] <= nums2[idx2]) {
                //剔除idx1及左边的
                k -= idx1 - l1 + 1;
                l1 = idx1 + 1;
            } else if (nums1[idx1] > nums2[idx2]) {
                k -= idx2 - l2 + 1;
                l2 = idx2 + 1;
            }
        }
    }
    double findMedianSortedArraysBetter(vector<int>& nums1,
                                        vector<int>& nums2) {
        return 0;
    };
};
/* int main() {
    vector<int> nums1{1};
    vector<int> nums2{2, 3, 4, 5, 6};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
} */
// @lc code=end
