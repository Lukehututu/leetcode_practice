/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 *
 * https://leetcode.cn/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (55.90%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 74.8K
 * Testcase Example:  '"RR.L"'
 *
 * n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。
 * 
 * 每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。
 * 
 * 如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。
 * 
 * 就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。
 * 
 * 给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：
 * 
 * 
 * dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
 * dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
 * dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
 * 
 * 
 * 返回表示最终状态的字符串。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：dominoes = "RR.L"
 * 输出："RR.L"
 * 解释：第一张多米诺骨牌没有给第二张施加额外的力。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：dominoes = ".L.R...LR..L.."
 * 输出："LL.RR.LLRRLL.."
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == dominoes.length
 * 1 <= n <= 10^5
 * dominoes[i] 为 'L'、'R' 或 '.'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        char Left = 'L';
        int i = 0;
        while(i < n) {
            int j = i;
            //找到一段连续的.
            while(j < n && dominoes[j] == '.') {
                j++;
            }

            //如果没到最右侧那就是本身，到了就假设它是向右倒的
            char Right = j < n ? dominoes[j] : 'R';
            
            //两边相同就往一边倒
            if(Left == Right) {
                while(i < j) {
                    dominoes[i++] = Left;
                }
            }
            //只有此时向中间倒
            else if(Left == 'R' && Right == 'L') {
                int k = j - 1;
                while(i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }

            i = j + 1;
            Left = Right;
        }
        return dominoes;
    }
};
// @lc code=end

