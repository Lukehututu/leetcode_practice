/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Medium (63.07%)
 * Likes:    3492
 * Dislikes: 0
 * Total Accepted:    544.4K
 * Total Submissions: 862.5K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));

        //初始化dp数组
        for(int i = 0;i < n + 1; ++i) {
            dp[i][0] = i;
        }

        for(int j = 0;j < m + 1; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < m + 1; ++j) {
                dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1] ,dp[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

