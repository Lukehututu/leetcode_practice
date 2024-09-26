/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (70.89%)
 * Likes:    1719
 * Dislikes: 0
 * Total Accepted:    662.1K
 * Total Submissions: 932.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //  计算行列 方便后面
        int row = grid.size();
        int col = grid[0].size();

        //  创建dp数组
        vector<vector<int>> dp(row,vector<int>(col,0));
        dp[0][0] = grid[0][0];

        //  初始化第一行和第一列
        for(int i = 1 ; i < col ; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < row; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        //  开始填充dp数组
        for(int i = 1; i < row; ++i)
        {
            for(int j = 1; j < col; ++j)
            {
                dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
};
// @lc code=end

