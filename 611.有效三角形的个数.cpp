/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode.cn/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (53.87%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    117.8K
 * Total Submissions: 217.1K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,2,3,4]
 * 输出: 3
 * 解释:有效的组合是: 
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [4,2,3,4]
 * 输出: 4
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        if(n < 3) return 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1;j < n - 1; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    if(nums[i] + nums[j] > nums[k]) {
                        ret++;
                    }
                    else break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

