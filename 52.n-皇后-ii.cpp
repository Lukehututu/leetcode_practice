/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.42%)
 * Likes:    524
 * Dislikes: 0
 * Total Accepted:    161.4K
 * Total Submissions: 195.7K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
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
    vector<vector<string>> best;
    int totalNQueens(int n) {
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
        return best.size();
    }

    void func(int i, const int &n, vector<string> vec)
    {
        if (i == n)
        {
            //  处理斜线
            //  从上往下判断
            for (int j = 0; j < n - 1; j++)
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

