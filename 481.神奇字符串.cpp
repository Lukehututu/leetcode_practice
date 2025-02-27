/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 *
 * https://leetcode.cn/problems/magical-string/description/
 *
 * algorithms
 * Medium (63.86%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    39.3K
 * Total Submissions: 61.7K
 * Testcase Example:  '6'
 *
 * 神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：
 * 
 * 
 * 神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连续出现次数可以生成该字符串。
 * 
 * 
 * s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，可以得到 "1 22 11
 * 2 1 22 1 22 11 2 11 22 ......" 。每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2
 * ......" 。上面的出现次数正是 s 自身。
 * 
 * 给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 6
 * 输出：3
 * 解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。 
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
 * 1 <= n <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        int index = 3;
        std::vector<bool> s{1, 0, 0};
        char c;
        for (int i = 3; i < n;) {
            if (s[index - 1] == 1) {//当前插入的一定跟末尾字符不同
                c = s[i - 1] == 1 ? 0 : 1;
                s.push_back(c);
                ++i;
            }
            else if (s[index - 1] == 0) {
                c = s[i - 1] == 1 ? 0 : 1;
                s.push_back(c);
                s.push_back(c);
                i += 2;
            }
            index++;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) if (s[i] == 1) cnt++;
        return cnt;
    }
};
// @lc code=end

