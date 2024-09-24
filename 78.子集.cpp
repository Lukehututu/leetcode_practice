/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.62%)
 * Likes:    2366
 * Dislikes: 0
 * Total Accepted:    861.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> x;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        int len = nums.size();
        func(ret,0,len,nums);
        return ret;
    }

    void func(vector<vector<int>>& ret,int i, int len,vector<int> nums)
    {
        if(i == len)
        {
            ret.push_back(x);
        }
        else
        {
            x.push_back(nums[i]);
            func(ret,i + 1,len,nums);
            x.pop_back();
            func(ret,i + 1,len,nums);
        }

    }
};
// @lc code=end

