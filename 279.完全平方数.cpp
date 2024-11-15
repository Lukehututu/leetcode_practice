/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (67.28%)
 * Likes:    2065
 * Dislikes: 0
 * Total Accepted:    607.1K
 * Total Submissions: 899.1K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 12
 * 输出：3 
 * 解释：12 = 4 + 4 + 4
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    int Min = 10000;
    vector<int> squArr;
    void backTrack(int i, int num, int n) {
        if (n == 0) {
            Min = min(Min, num);
            return;
        }
        if (n < 0 || i < 1 || num >= Min)
            return;
        //  选择
        if (n >= squArr[i])
            backTrack(i, num + 1, n - squArr[i]);
        //  不选择
        backTrack(i - 1, num, n);
        
    }

    int numSquares(int n) {
        //  先用一个hashmap存完全平方数
        for (int i = 0; i <= 100; ++i) {
            squArr.push_back(i * i);
        }

        //  倒着回溯，先找到离n最近的平方数
        int i = 1;
        for (; i < n; ++i) {
            if (squArr[i] >= n) {
                i = squArr[i] == n ? i : i - 1;
                break;
            }
        }
        if (squArr[i] == n)
            return 1;

        backTrack(i, 0, n);
        return Min;
    }
};
// @lc code=end

