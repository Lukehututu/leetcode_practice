/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 *
 * https://leetcode.cn/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (54.39%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    79.2K
 * Total Submissions: 145.1K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
 * 
 * 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
 * 
 * 
 * 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
 * 
 * 
 * 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
 * 
 * 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
 * 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
 * 
 * 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：start = "AACCGGTT", end = "AAACGGTA", bank =
 * ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：start = "AAAAACCC", end = "AACCCCCC", bank =
 * ["AAAACCCC","AAACCCCC","AACCCCCC"]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * start.length == 8
 * end.length == 8
 * 0 <= bank.length <= 10
 * bank[i].length == 8
 * start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> isValid;
        unordered_set<string> visited;
        char key[4] = {'A','C','G','T'};
        for(auto m : bank) {
            isValid.emplace(m);
        }
        if(startGene == endGene) return 0;
        if(isValid.count(endGene) == 0) return -1;

        isValid.emplace(startGene);
        visited.emplace(startGene);
        queue<string> qu;
        qu.push(startGene);
        int step = 1;
        while(!qu.empty()) {
            int size = qu.size();
            //这一次的for loop中的str要比上一次的多修改了一个字母
            for(int i = 0; i < size; i++) {
                string cur = qu.front();
                qu.pop();
                for(int n = 0; n < 8; ++n) {
                    for(int m = 0; m < 4; ++m) {
                        if(key[m] != cur[n]) {
                            string next = cur;
                            next[n] = key[m];
                            //修改完后的str如果既没被visited过同时也是有效的那就加入修改队列中
                            if(isValid.count(next) > 0 && visited.count(next) == 0) {
                                if(next == endGene) {
                                    return step;
                                } 
                                visited.emplace(next);
                                qu.push(next);
                            }
                        }
                    }
                }
            }
            step++;
        }

        //出来的都是不能正确变化得到的
        return -1;
    }
};
// @lc code=end

