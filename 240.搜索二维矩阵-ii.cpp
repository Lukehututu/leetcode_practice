/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (54.31%)
 * Likes:    1535
 * Dislikes: 0
 * Total Accepted:    516K
 * Total Submissions: 948K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * 每行的所有元素从左到右升序排列
 * 每列的所有元素从上到下升序排列
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    //  实际上1个元素从左下角往上逼近就行*************************
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int width = matrix.size(); //   行
        int length = matrix[0].size(); //   列
        //  (行，列)
        pair<int, int> leftUp(0,0);
        pair<int, int> rightDown(width - 1,length - 1);

        //  整体思想
        /*
            左上角往左下角逼近，右下角往左上角逼近
        */

         while (leftUp != rightDown)
        {
            if (matrix[leftUp.first][leftUp.second] == target
                || matrix[rightDown.first][rightDown.second] == target
                || matrix[leftUp.first][leftUp.second] == target
                || matrix[leftUp.first][rightDown.second] == target) return true;
            //  如果target比最小的还小，或者比最大的还大，那就false
            if (matrix[leftUp.first][leftUp.second] > target
                || matrix[rightDown.first][rightDown.second] < target)  return false;
            //  如果左上角同行的最后一位比target小 那first++
            if (matrix[leftUp.first][rightDown.second] < target) leftUp.first++;
            //  如果左上角同列的最后一位比target小 那second++
            else if (matrix[rightDown.first][leftUp.second] < target) leftUp.second++;
            //  如果右下角同行的第一位比target大 那first--
            else if (matrix[rightDown.first][leftUp.second] > target) rightDown.first--;
            //  如果右下角同列的第一位比target大 那first--
            else if (matrix[leftUp.first][rightDown.second] > target) rightDown.second--;
        }
        if (matrix[leftUp.first][leftUp.second] == target)
            return true;
        return false;
    }
};
// @lc code=end

