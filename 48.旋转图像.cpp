/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (76.89%)
 * Likes:    1945
 * Dislikes: 0
 * Total Accepted:    654.6K
 * Total Submissions: 847.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    //  v1 -- 借助新数组旋转
    // void rotate(vector<vector<int>>& matrix) {
    //     // 算出矩阵长度
    //     int len = matrix[0].size();
    //     auto new_matrix = matrix;
    //     for(int i = 0; i < len; i++)
    //     {
    //         for(int j = 0; j < len;j++)
    //         {
    //             new_matrix[j][len - i - 1] = matrix[i][j];
    //         }
    //     }
    //     matrix = new_matrix;
    //     return ;
    // }

    //  v2 -- 在原地旋转
    void rotate(vector<vector<int>>& matrix) {
        // 算出矩阵长度
        int len = matrix[0].size();
        for(int i = 0; i < len / 2 + 1; i++)
        {   
            for(int j = i; j < len - i - 1; j++)
            {
                //  记录原先的变量
                auto tmp = matrix[i][j];
                //  将四个变量连续调整
                matrix[i][j] = matrix[len - j - 1][i];
                matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
                matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
                matrix[j][len - i - 1] = tmp;
            }
        }
        return ;
    }
};
// @lc code=end

