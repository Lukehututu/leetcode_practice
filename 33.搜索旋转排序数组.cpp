/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (44.54%)
 * Likes:    3021
 * Dislikes: 0
 * Total Accepted:    958.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始
 * 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[i] == nums[j]) return nums[i] == target ? i : -1;
            else if (nums[mid] == target)return mid;
            // 此时说明还是两段
            else if (nums[i] > nums[j]) {
                if (nums[mid] > nums[i]) {
                    if (target >= nums[i] && target < nums[mid])
                        j = mid - 1;
                    else
                        i = mid + 1;
                }
                else if (nums[mid] == nums[i]) {
                        i = mid + 1;
                }
                else {
                    if (target > nums[mid] && target <= nums[j])
                        i = mid + 1;
                    else
                        j = mid - 1;
                }
            }
            //  此时就是升序
            else if (nums[i] < nums[j]) {
                if (nums[mid] < target) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

