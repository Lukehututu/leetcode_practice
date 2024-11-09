/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (76.32%)
 * Likes:    1896
 * Dislikes: 0
 * Total Accepted:    556.8K
 * Total Submissions: 726.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * 
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 * 
 * 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans;
        ans.resize(nums.size());
        int product = 1;
        int zero_cnt = 0;
        int j = 0;
        int pos = 0;
        for(int n : nums)
        {
            if(n != 0)
                product *= n;
            if (n == 0)
            {
                zero_cnt++;
                pos = j;
            }
            j++;
        }
        if(zero_cnt == 0)
        {
            for(int i = 0;i < nums.size();i++)
            {
                ans[i] = (product / nums[i]);
            }
            return ans;
        }

        for(int i = 0;i < nums.size();i++)
            ans[i] = 0;
        if(zero_cnt == 1)
            ans[pos] = product;
        return ans;        
    
    }
};
// @lc code=end

