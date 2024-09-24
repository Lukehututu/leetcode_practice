/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (78.04%)
 * Likes:    3686
 * Dislikes: 0
 * Total Accepted:    908.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // 如果当前字符串的长度等于 2n，说明一个组合完成
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // 如果还有左括号可以添加
        if (open < n) {
            backtrack(result, current + '(', open + 1, close, n);
        }

        // 如果可以添加右括号（右括号的数量要小于左括号的数量）
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, n);
        }
    }



};
// @lc code=end

