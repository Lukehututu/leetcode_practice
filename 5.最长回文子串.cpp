/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.65%)
 * Likes:    7325
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 4.6M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start


class Solution {
public:
    string longestPalindrome(string s) {
        int l{},r{};
        for(int i = 0;i < s.size() * 2 - 1; ++i) {
            int left = i / 2, right = (i + 1) / 2;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            if(right - 1 - left - 1 > r - l) {
                r = right - 1;
                l = left + 1;
            }
        }
        
        return string(s.begin() + l,s.begin() + r + 1);
    }
};
// @lc code=end

