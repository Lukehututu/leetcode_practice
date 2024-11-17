/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.00%)
 * Likes:    1851
 * Dislikes: 0
 * Total Accepted:    640.3K
 * Total Submissions: 926K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);

        //维护一个单调栈
        stack<int> monotonic_stack;
        int preIndex = 0;   //维护栈顶坐标
        for (int i = 0; i < temperatures.size(); ++i) {
            //如果栈空，直接压栈
            if (monotonic_stack.empty()) {
                preIndex = i;
                monotonic_stack.push(i);
            }

            while (temperatures[i] > temperatures[preIndex] && !monotonic_stack.empty()) {
                ans[preIndex] = i - preIndex;
                monotonic_stack.pop();
                if (!monotonic_stack.empty())
                    preIndex = monotonic_stack.top();
            }

            if (temperatures[i] <= temperatures[preIndex]) {
                preIndex = i;
                monotonic_stack.push(i);
            }
            //否则就是栈为空了
            else {
                preIndex = i;
                monotonic_stack.push(i);
            }
        }
        //如果栈不为空，那将其中所有下标对应的ans都置为0
        //但实际上一开始初始化为0了，因此就不用再手动设置了
        return ans;
    }
};
// @lc code=end

