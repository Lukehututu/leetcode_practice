/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode.cn/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (37.98%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    167.9K
 * Total Submissions: 435.2K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：c = 3
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (long)sqrt(c);
        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c)
                return true;
            else if (sum > c)
                right--;
            else
                left++;
        }
        return false;
    }
};
// @lc code=end

