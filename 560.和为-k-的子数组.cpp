/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.25%)
 * Likes:    2517
 * Dislikes: 0
 * Total Accepted:    564.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 * 
 * 子数组是数组中元素的连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map; //  存储前缀和为key 出现的次数为val
        map[0] = 1; //  一开始一个元素不选就是0 出现1次
        int cnt = 0; // 子数组个数

        int pre = 0;
        for(auto& n : nums)
        {
            pre += n;
            if(map.find(pre - k) != map.end())  //  如果找到了有这样的前缀
            {
                cnt += map[pre - k];
            }
            map[pre]++;
        }
        return cnt;        
    }
};
// @lc code=end

