/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (56.33%)
 * Likes:    726
 * Dislikes: 0
 * Total Accepted:    108.3K
 * Total Submissions: 191.7K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
 * 
 * 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c)
 * 上单元格 高于海平面的高度 。
 * 
 * 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
 * 
 * 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动
 * 既可流向太平洋也可流向大西洋 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: heights = [[2,1],[1,2]]
 * 输出: [[0,0],[0,1],[1,0],[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    void dfs(int i, int j, int m, int n, std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& ocean) {
        ocean[i][j] = true;

        // 四个方向
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;

            // 条件：在矩阵范围内、未访问过、高度不低于当前单元格
            if (x >= 0 && x < m && y >= 0 && y < n && !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(x, y, m, n, heights, ocean);
            }
        }
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int m = heights.size();
            int n = heights[0].size();
            std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
            std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));

            // 从太平洋边界（左边界和上边界）开始 DFS
            for (int i = 0; i < m; ++i) dfs(i, 0, m, n, heights, pacific);
            for (int j = 0; j < n; ++j) dfs(0, j, m, n, heights, pacific);

            // 从大西洋边界（右边界和下边界）开始 DFS
            for (int i = 0; i < m; ++i) dfs(i, n - 1, m, n, heights, atlantic);
            for (int j = 0; j < n; ++j) dfs(m - 1, j, m, n, heights, atlantic);

            // 找到同时能流向太平洋和大西洋的单元格
            std::vector<std::vector<int>> result;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (pacific[i][j] && atlantic[i][j]) {
                        result.push_back({i, j});
                    }
                }
            }

            return result;
        }

};
// @lc code=end

