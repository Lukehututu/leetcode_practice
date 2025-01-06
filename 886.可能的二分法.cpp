/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 *
 * https://leetcode.cn/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (52.51%)
 * Likes:    418
 * Dislikes: 0
 * Total Accepted:    55.6K
 * Total Submissions: 105.7K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * 给定一组 n 人（编号为 1, 2, ..., n）， 我们想把每个人分进任意大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。
 * 
 * 给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和
 * bi的人归入同一组。当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, dislikes = [[1,2],[1,3],[2,4]]
 * 输出：true
 * 解释：group1 [1,4], group2 [2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3, dislikes = [[1,2],[1,3],[2,3]]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2000
 * 0 <= dislikes.length <= 10^4
 * dislikes[i].length == 2
 * 1 <= dislikes[i][j] <= n
 * ai < bi
 * dislikes 中每一组都 不同
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n == 1 ||  dislikes.size() == 0) return true;
        sort(dislikes.begin(), dislikes.end(), [](std::vector<int>& a, std::vector<int>& b) {
            if (a[0] == b[0]) return a[1] <= b[1];
            return a[0] < b[0];
            });
        std::vector<int> bucket(n + 1, 0);
        //traversal dislikes
        for (int i = 0; i < dislikes.size(); ++i) {
            int fir = dislikes[i][0], secd = dislikes[i][1];
            //如果 这俩个由于之前的关系已经装在了同一个桶里 return false
            if (bucket[fir] == bucket[secd] && bucket[fir] != 0) return false;
            if (bucket[fir] == 0 && bucket[secd] == 0) {
                bucket[fir] = 1;
                bucket[secd] = 2;
            }
            else {
                if (bucket[fir] != 0) bucket[secd] = bucket[fir] == 1 ? 2 : 1;
                else if (bucket[secd] != 0) bucket[fir] = bucket[secd] == 1 ? 2 : 1;
            }

        }
        //出来说明能够正确装完，则return true; 
        return true;
    }
};
// @lc code=end

