/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (50.43%)
 * Likes:    2430
 * Dislikes: 0
 * Total Accepted:    971.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //  先给所有区间按左边界排序
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans;    //  返回值vec
        vector<int> x = intervals[0];   //  表示当前数组
        
        for(int i = 1;i < intervals.size();i++)
        {
            //  那此时就是完整区间
            if(x[1] < intervals[i][0] && x[1] <= intervals[i][1])
            {
                ans.push_back(x);
                //  同时x更新为当前区间
                x = intervals[i];
            }
            else if(x[1] > intervals[i][1])
            {
                continue;
            }
            //  否则需要更新区间右值
            else
            {
                x[1] = intervals[i][1];
            }
            
        }
        //  最后一个x没有下一个数组了因此直接加入
        ans.push_back(x);
        return ans;
    }
};
// @lc code=end

