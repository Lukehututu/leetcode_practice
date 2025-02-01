/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 *
 * https://leetcode.cn/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (55.23%)
 * Likes:    901
 * Dislikes: 0
 * Total Accepted:    105.5K
 * Total Submissions: 190.2K
 * Testcase Example:  '"ABAB"\n2'
 *
 * 给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
 * 
 * 在执行上述操作后，返回 包含相同字母的最长子字符串的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ABAB", k = 2
 * 输出：4
 * 解释：用两个'A'替换为两个'B',反之亦然。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "AABABBA", k = 1
 * 输出：4
 * 解释：
 * 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
 * 子串 "BBBB" 有最长重复字母, 答案为 4。
 * 可能存在其他的方法来得到同样的结果。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 仅由大写英文字母组成
 * 0 <= k <= s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        bool occ[26]{false};
        for(char ch : s) {
            occ[ch - 'A'] = true;
        }

        int res = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++) {
            if(occ[ch - 'A'] == false) continue;
            int i = 0, j = 0;
            int cnt = 0;
            while(j < n) {
                if(s[j] != ch) cnt++;
                while(cnt > k) {
                    if(s[i] != ch) cnt--;
                    i++;
                }
                res = max(res, j - i + 1);
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

