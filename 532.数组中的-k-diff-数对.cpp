/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 *
 * https://leetcode.cn/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (46.36%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 149.6K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。
 * 
 * k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：
 * 
 * 
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] - nums[j]| == k
 * 
 * 
 * 注意，|val| 表示 val 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3, 1, 4, 1, 5], k = 2
 * 输出：2
 * 解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
 * 尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1, 2, 3, 4, 5], k = 1
 * 输出：4
 * 解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1, 3, 1, 5, 4], k = 0
 * 输出：1
 * 解释：数组中只有一个 0-diff 数对，(1, 1) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^7 <= nums[i] <= 10^7
 * 0 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //1.先对数组降序排列 -- 不关心下标只关心数值
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            return a > b;
        });
        int cnt = 0;
        //2.双指针 从两边到中间
        for(int i = 0; i < nums.size(); ++i) {
            if(i >= 1 && nums[i] == nums[i - 1]) continue;
            int j = nums.size() - 1;
            while(i < j) {
                if(nums[i] - nums[j] == k) {
                    cnt++;
                    break;
                }
                j--;
            }
        }
        return cnt;
    }
};
// @lc code=end

