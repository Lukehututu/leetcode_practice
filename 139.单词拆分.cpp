/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (56.34%)
 * Likes:    2616
 * Dislikes: 0
 * Total Accepted:    681.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
 * 
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅由小写英文字母组成
 * wordDict 中的所有字符串 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.size(), 0);
        vector<int> isValid;
    
        for (int i = 0; i < s.size(); ++i) {
            int k = isValid.size() - 1;
            for (; k >= 0; --k) {
                //  此时只需保证S(j + 1, i)这一段有效即可
                int j = isValid[k];
                string tmp(s.begin() + 1 + j, s.begin() + i + 1);
                for (string str : wordDict) {
                    if (str == tmp) {
                        dp[i] = true;
                        isValid.emplace_back(i);
                        break;
                    }
                }
                if (dp[i])break;
            }
            //  那有可能是从头开始
            if (k == -1) {
                int j = 0;
                string tmp(s.begin(), s.begin() + i + 1);
                for (string str : wordDict) {
                    if (str == tmp) {
                        dp[i] = true;
                        isValid.emplace_back(i);
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end

