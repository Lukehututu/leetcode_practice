/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.33%)
 * Likes:    2133
 * Dislikes: 0
 * Total Accepted:    440.8K
 * Total Submissions: 592.6K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    //  该数组用于返回
    vector<vector<string>> best;

    vector<vector<string>> solveNQueens(int n) {

        //  该数组用于修改
        vector<string> vec;
        string str = "";
        for(int i = 0;i < n;i++)
        {
            str +=".";
        }
        for(int i = 0;i < n;i++)
        {
            str[i] = 'Q'; 
            vec.push_back(str);
            str[i] = '.'; 
        }

        //  以上步骤处理完了横线和竖线
        func(0,n,vec);
        return best;
    }
    void func(int i, const int &n, vector<string> vec)
    {
        if (i == n)
        {
            //  处理斜线
            //  从上往下判断
            for (int j = 1; j < n - 1; j++)
            {
                int a = vec[j].find('Q');
                for (int m = j + 1; m < n; m++)
                {
                    int b = vec[m].find('Q');
                    if (abs(b - a) == abs(m - j))
                    {
                        return;
                    }
                }
            }

            best.push_back(vec);

        }
        else
        {
            for (int k = i; k < n; k++)
            {
                swap(vec[i], vec[k]);
                func(i + 1, n, vec);
                swap(vec[i], vec[k]);
            }
        }
    }
};
// @lc code=end

