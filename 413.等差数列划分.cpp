/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 *
 * https://leetcode.cn/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    132.6K
 * Total Submissions: 191.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
 * 
 * 
 * 例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
 * 
 * 
 * 
 * 
 * 给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
 * 
 * 子数组 是数组中的一个连续序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：3
 * 解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -1000 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0, j = 2;
        if(n < 3) return 0;
        while(j < n) {
            //从j项开始不满足等差
            if(nums[j] - nums[j - 1] != nums[j - 1] - nums[j - 2]) {
                if(j - i >= 3) {//j之前要足够3项
                    ans += (1 + j - i - 2) * (j - i - 2) / 2;//更新序列数
                }
                i = j - 1; //更新窗口左边界 -- 如果不对那新的数列的前两项就是i j
            }
            j++;
        }
        //处理仍然是等差 但j == n 了
        if(j - i >= 3) { // 只要出来且中间至少有三个元素那一定是等差数列，因为如果不是 他们之间一定i = j - 1 同时 j++只有两个
            ans += (1 + j - i - 2) * (j - i - 2) / 2;
        }
        return ans;
    }
};
// @lc code=end

