/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (55.59%)
 * Likes:    6791
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 3.3M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 子数组 是数组中的一个连续部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 * 
 */

// @lc code=start
class Solution {
public:

    /*
        dp[0] = nums[0]
        dp[1] = max(nums[1],nums[1] + dp[0])
        dp[2] = max(nums[2],nums[2] + dp[1])
        ...
        dp[i] = max(nums[i],nums[i] + dp[i-1])
    */

    int maxSubArray(vector<int>& nums) {
        int cur_max = nums[0];
        int global_max = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            cur_max = max(nums[i],nums[i] + cur_max);
            global_max = max(cur_max,global_max);
        }

       return global_max;
    }

    
};
// @lc code=end

