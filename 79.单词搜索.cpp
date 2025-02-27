/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (47.46%)
 * Likes:    1898
 * Dislikes: 0
 * Total Accepted:    595.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isExist{false};
   
    void verifyExist(int i, int j, string &word, int n, vector<vector<char>> &board, vector<vector<bool>>& isChoose)
    {
        if (n == word.size())
        {
            isExist = true;
        }
        else
        {
            if (i - 1 >= 0 && isChoose[i - 1][j] == false && board[i - 1][j] == word[n]) {
                isChoose[i - 1][j] = true;
                verifyExist(i - 1, j, word, n + 1, board,isChoose);
                isChoose[i - 1][j] = false;
            }
                
            if (i + 1 < board.size() && isChoose[i + 1][j] == false  && board[i + 1][j] == word[n]) {
                isChoose[i + 1][j] = true;
                verifyExist(i + 1, j, word, n + 1, board,isChoose);
                isChoose[i + 1][j] = false;
            }
            if (j - 1 >= 0 && isChoose[i][j - 1] == false  && board[i][j - 1] == word[n]) {
                isChoose[i][j - 1] = true;
                verifyExist(i, j - 1, word, n + 1, board,isChoose);
                isChoose[i][j - 1] = false;
            }
            if (j + 1 < board[0].size() && isChoose[i][j + 1] == false  && board[i][j + 1] == word[n]) {
                isChoose[i][j + 1] = true;
                verifyExist(i, j + 1, word, n + 1, board,isChoose);
                isChoose[i][j + 1] = false;
            }
        }
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> isChoose(board.size(),vector<bool>(board[0].size(),false));
        for (int i = 0; i < board.size(); ++i)
        {
            if (isExist)
                break;
            for (int j = 0; j < board[0].size(); ++j)
            {
                if(isExist)
                    break;
                if (board[i][j] == word[0])
                {
                    isChoose[i][j] = true;
                    verifyExist(i, j, word, 1, board,isChoose);
                    isChoose[i][j] = false;
                }
            }
        }
        return isExist;
    }
};
// @lc code=end

