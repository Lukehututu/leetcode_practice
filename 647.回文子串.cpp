/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (67.56%)
 * Likes:    1381
 * Dislikes: 0
 * Total Accepted:    364.1K
 * Total Submissions: 538.2K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        //中心拓展法
        int n = s.size();
        int ans{};
        for(int i = 0;i < 2 * n - 1; ++i) {
            int l = i / 2;
            int r = (i + 1) / 2;
            while (l >=0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

