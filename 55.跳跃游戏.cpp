/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode.cn/problems/jump-game/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    2872
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 * 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1,0,4]
 * 输出：false
 * 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //     if(nums.size() == 1)
    //         return true;
    //     vector<bool> dp(nums.size(),0);

    //     //  倒着来填充dp数组
    //     for(int i = nums.size() - 2; i >= 0;i--)
    //     {
    //         if(nums[i] + i >= nums.size() - 1)
    //             dp[i] = true;
    //         else
    //         {
    //             //  轮询能跳到的下标，看这些下标能不能到最后一个
    //             for(int j = nums[i];j >= 1;j--)
    //             {
    //                 if(dp[i+j] == true)
    //                 {
    //                     dp[i] = true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0];
    // }

    //  贪心思想
     bool canJump(vector<int>& nums) {
        
        int most = 0;
        for(int i = 0;i <= nums.size() - 1; i++)
        {
            //  如果能走到i才比较
            if(i <= most)
            {
                most = max(most,nums[i] + i);
                if(most >= nums.size() - 1)
                    return true;
            }

        }
        return false;
    }
};
// @lc code=end

