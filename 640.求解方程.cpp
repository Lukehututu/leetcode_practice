/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 *
 * https://leetcode.cn/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (44.38%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    40K
 * Total Submissions: 90.1K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
 * 
 * 如果方程没有解或存在的解不为整数，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
 * 
 * 题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: equation = "x+5-3+x=6+x-2"
 * 输出: "x=2"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: equation = "x=x"
 * 输出: "Infinite solutions"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: equation = "2x=x"
 * 输出: "x=0"
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 3 <= equation.length <= 1000
 * equation 只有一个 '='. 
 * 方程由绝对值在 [0, 100]  范围内且无任何前导零的整数和变量 'x' 组成。​​​
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
       istringstream ss(equation);
        int sign = 1, side = 1, cNum{}, xNum{}, tmpNum;

        for(char ch; ss >> ch;) {
            if(ch == '+') sign = 1;
            else if(ch == '-') sign = -1;
            else if(ch == '=') {
                sign = 1;
                side = -1;
            }
            //单独一个x
            else if(ch == 'x') xNum += sign * side;
            else {
                ss.unget();
                ss >> tmpNum;
                //如果下一个字符是x，就计算x的系数
                if(ss.peek() == 'x') {
                    ss.get();
                    xNum += tmpNum * side * sign;
                }
                else {
                    cNum += tmpNum * side * sign;
                }
            }
        }

        if(xNum == 0) return cNum ? "No solution" : "Infinite solutions";
        return "x=" + to_string(-1 * cNum / xNum);
    }
};
// @lc code=end

