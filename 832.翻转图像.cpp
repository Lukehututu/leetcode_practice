/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 *
 * https://leetcode.cn/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (79.57%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    110.3K
 * Total Submissions: 138.5K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * 给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
 * 
 * 水平翻转图片就是将图片的每一行都进行翻转，即逆序。
 * 
 * 
 * 例如，水平翻转 [1,1,0] 的结果是 [0,1,1]。
 * 
 * 
 * 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
 * 
 * 
 * 例如，反转 [0,1,1] 的结果是 [1,0,0]。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：image = [[1,1,0],[1,0,1],[0,0,0]]
 * 输出：[[1,0,0],[0,1,0],[1,1,1]]
 * 解释：首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
 * ⁠    然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * 输出：[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 解释：首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
 * ⁠    然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * n == image.length
 * n == image[i].length
 * 1 <= n <= 20
 * images[i][j] == 0 或 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); ++i) {
            reverse(image[i].begin(), image[i].end());
            for(auto& i : image[i]) {
                i = (i==1)? 0 : 1;
            }
        }
        return image;
    }

};
// @lc code=end

