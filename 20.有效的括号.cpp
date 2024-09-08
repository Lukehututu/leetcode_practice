/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.16%)
 * Likes:    4529
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.4M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([])"
 * 
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start

class Solution {
public:


    bool isValid(string s) {
        stack<char> p;
        stack<char> q;
        for(char i : s)
        {
            p.push(i);
        }

        while(!p.empty())
        {
            auto tmp = p.top();
            p.pop();

            //  如果是右括号就入栈
            if(tmp ==']' || tmp == ')' || tmp == '}')
                q.push(tmp);
            
            //  如果是左括号，就判断q是否要出栈
            if(tmp =='[' || tmp == '(' || tmp == '{')
            {
                if(!q.empty())
                {
                    auto q_top = q.top();
                    auto dis = tmp - q_top;
                    //  此时说明匹配上了 q就出栈
                    if(dis == -2 || dis == -1)
                        q.pop();
                    else
                        q.push(tmp);
                }
                else
                    return false;
            }

        }
        return q.empty();
    }
};
// @lc code=end

