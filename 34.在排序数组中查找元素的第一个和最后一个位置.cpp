/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (44.00%)
 * Likes:    2837
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        //  两个log(n)分别求出左右边界

        //  [i,j] 
        //  nums[i] == target && nums[i - 1] < target || i - 1 < 0
        //  nums[j] == target && nums[j + 1] > target || j + 1 > 0

        int a{}, b{};
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                if (mid - 1 < 0 || nums[mid - 1] < target) {
                    a = mid;
                    break;
                }
                else
                    j = mid - 1;
            }
            else if (nums[mid] < target) {
                i = mid + 1;
            }
            else if (nums[mid] > target) {
                j = mid - 1;
            }
        }
        if(i > j)
            return vector<int> {-1, -1};
        else if (i == j) {
            if (nums[i] == target) {
                a = i;
            }
            else
                return vector<int> {-1, -1};
        }
        j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                if (mid + 1 == nums.size() || nums[mid + 1] > target) {
                    b = mid;
                    break;
                }
                else
                    i = mid + 1;
            }
            else if (nums[mid] > target)
                j = mid - 1;
        }
        if (i == j) {
            nums[i] == target;
            b = i;
        }
        return vector<int>{a, b};
    }
};
// @lc code=end

