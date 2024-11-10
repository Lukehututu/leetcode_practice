/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode.cn/problems/sort-colors/description/
 *
 * algorithms
 * Medium (61.65%)
 * Likes:    1848
 * Dislikes: 0
 * Total Accepted:    699.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 
 * 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_cnt = 0;
        int one_cnt = 0;
        int two_cnt = 0;
        for(int i : nums)
        {
            zero_cnt = i == 0? zero_cnt + 1 : zero_cnt;
            one_cnt = i == 1? one_cnt + 1 : one_cnt;
            two_cnt = i == 2? two_cnt + 1 : two_cnt;
        }

        for(int i = 0;i < nums.size();i++)
        {
            if(i < zero_cnt)
                nums[i] = 0;
            else if(i < one_cnt)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
        return;
    }
};
// @lc code=end

