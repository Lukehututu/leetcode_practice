/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 *
 * https://leetcode.cn/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (61.53%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    89.3K
 * Total Submissions: 144.8K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
 * 
 * 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
 * 
 * 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * 输出：3
 * 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * 输出：0
 * 解释：所有 1 都在边界上或可以到达边界。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] 的值为 0 或 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid, bool& exit, int& sz) {
        visited[i][j] = true;
        sz++;
        if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) {
            exit = true;
        }
        vector<vector<int>> off({{-1, 0},{1, 0},{0, -1},{0, 1}});
        for(auto vec : off) {
            int x = vec[0] + i;
            int y = vec[1] + j;
            if(x >= 0 && x < visited.size() && y >= 0 && y < visited[0].size() 
             && visited[x][y] == false && grid[x][y] == 1) 
                dfs(x, y, visited, grid, exit, sz);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int num = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    bool exit = false;
                    int sz = 0;//？？？
                    dfs(i ,j , visited, grid, exit, sz);
                    num = exit ? num : num + sz;
                }
            }
        }
        return num;
    }
};
// @lc code=end

