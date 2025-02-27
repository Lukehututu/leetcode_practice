/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (55.02%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    216K
 * Total Submissions: 389.4K
 * Testcase Example:  '"IceCreAm"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "IceCreAm"
 * 
 * 输出："AceCreIm"
 * 
 * 解释：
 * 
 * s 中的元音是 ['I', 'e', 'e', 'A']。反转这些元音，s 变为 "AceCreIm".
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcode"
 * 
 * 输出："leotcede"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string dir = "aeiouAEIOU";
        int i = 0, j = s.length() - 1;
        while(i < j) {
            //先找到元音
            while(i < j && dir.find(s[i]) > 9) i++;
            while(i < j && dir.find(s[j]) > 9) j--;
            if(i < j) swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};
// @lc code=end

