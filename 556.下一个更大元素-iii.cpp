/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 *
 * https://leetcode.cn/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (36.83%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    52.9K
 * Total Submissions: 143.5K
 * Testcase Example:  '12'
 *
 * 给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。
 * 
 * 注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 12
 * 输出：21
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 21
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        
        string num = to_string(n);
        int size = num.size();
        int i = size - 2;
        for (; i >= 0; i--) {
            if (num[i] < num[i + 1]) break;
        }
        if (i == -1) return -1;

        //此时i + 1 ~ n - 1都是降序排列
        int j = size - 1;
        for (; j > i; j--) {
            if (num[j] > num[i]) break;
        }
        swap(num[j], num[i]);
        //再将 i + 1 ~ n - 1升序
        sort(num.begin() + i + 1, num.end());
        long ret = stol(num);
        if(ret > INT_MAX) return -1;
        return ret;
    }
};
// @lc code=end

