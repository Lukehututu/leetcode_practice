/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode.cn/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (44.79%)
 * Likes:    1689
 * Dislikes: 0
 * Total Accepted:    604K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 
 * 返回这三个数的和。
 * 
 * 假定每组输入只存在恰好一个解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int off = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if(tmp == target) return target;
                if(abs(tmp - target) < off) {
                    sum = tmp;
                    off = abs(tmp - target);
                }
                if(tmp < target) { //此时小的太小了 -- 更新j
                    int t = j + 1;
                    while (t < n && nums[t] == nums[j]) t++;
                    j = t;
                }
                else {//此时大的太大了 -- 更新 k
                    int t = k - 1;
                    while (t > 0 && nums[t] == nums[k]) t--;
                    k = t;
                }
            }
        }
        return sum;
    }
};
// @lc code=end

