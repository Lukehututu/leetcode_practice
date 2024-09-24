/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (79.60%)
 * Likes:    2971
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> vec;
        vector<int> out;
        bool state[6] = {false};
        func(vec,0,nums.size(),out,nums,state);
        return vec;
    }

    void func(vector<vector<int>>& vec, int i,int len,vector<int> out,vector<int> nums,bool state[])
    {
        if (i == len)
        {
           vec.push_back(out);
        }
        else
        {
            for (int k = 0; k < len; k++)
            {
                if (!state[k])
                {
                    out.push_back(nums[k]);
                    state[k] = true;
                    func(vec,i + 1,nums.size(),out,nums,state);
                    out.pop_back();
                    state[k] = false;
                }
            }
        }
    }
};
// @lc code=end

