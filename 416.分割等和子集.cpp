/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.70%)
 * Likes:    2194
 * Dislikes: 0
 * Total Accepted:    644K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    // bool ans{false};
    // void backTrack(int i,vector<int>& nums,int sum, int target,int acc) {
    //     if(sum == target) {
    //         ans = true;
    //         return;
    //     }
    //     else {
    //         if(!ans && i < nums.size()) {
    //             acc -= nums[i];
    //             if(acc + sum >= target) {
    //                 sum += nums[i];
    //                 backTrack(i + 1,nums,sum,target,acc);
    //                 sum -= nums[i];
    //                 backTrack(i + 1,nums,sum,target,acc);
    //             } 
    //         }
    //     }
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int MaxNum = *max_element(nums.begin(),nums.end());
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        if(MaxNum > target) return false;

        vector<vector<int>> dp(n,vector<int>(target + 1,false));
        for(auto& vec : dp) {
            vec[0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; ++i) {
            int num = nums[i];
            for(int j = 1; j <= target; ++j) {
                if(j >= num)
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
    
        return dp[n - 1][target];
    }
};
// @lc code=end

