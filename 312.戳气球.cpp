/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode.cn/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (70.77%)
 * Likes:    1417
 * Dislikes: 0
 * Total Accepted:    134.1K
 * Total Submissions: 189.5K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i
 * - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,5,8]
 * 输出：167
 * 解释：
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,5]
 * 输出：10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    void backTrace(int n,vector<int>& nums,int coins,int& Max) {
        if(n == 0) {
            Max = max(coins,Max);
            return;
        }
        else {
        
            for(int j = 0; j < nums.size(); j = (j + 1)) {
                //戳破
                if(nums[j] != -1) {
                    int mid = nums[j];

                    int left = j - 1;
                    while (left >= 0 && nums[left] == -1) left--;
                    if(left == -1) left = 1;
                    else left = nums[left];
                    
                    int right = j + 1;
                    while (right < nums.size() && nums[right] == -1) right++;
                    if(right == nums.size()) right = 1;
                    else right = nums[right];

                    nums[j] = -1;
                    backTrace(n - 1,nums,coins + left * mid * right,Max);
                    nums[j] = mid;
                }
                
            }
        }

    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int Max = 0;
        //有可能nums[i] == 0; 
        backTrace(nums.size(),nums,0,Max);
        return Max;
    }
};
// @lc code=end

