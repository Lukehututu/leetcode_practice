/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (61.19%)
 * Likes:    2619
 * Dislikes: 0
 * Total Accepted:    948.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    void Dfs(vector<vector<char>>& grid,int i,int j) {
        int row = grid.size();
        int col = grid[0].size();

        grid[i][j] = '0';
        if(i - 1 >= 0 && grid[i - 1][j] == '1')Dfs(grid,i - 1,j);
        if(i + 1 < row && grid[i + 1][j] == '1')Dfs(grid,i + 1,j);
        if(j - 1 >= 0 && grid[i][j - 1] == '1')Dfs(grid,i,j - 1);
        if(j + 1 < col && grid[i][j + 1] == '1')Dfs(grid,i,j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;

        int nums_island = 0;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1'){
                    ++nums_island;
                    Dfs(grid,i,j);
                }
            }
        }
        
        return nums_island;
    }
};
// @lc code=end

