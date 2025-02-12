/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int Max = 0, Min = 0; 

        for(int i = 0; i < n - 1; ++i) {
            Max = nums[i];
            Min = nums[i];
            for(int j = i + 1; j < n; ++j) {
                Max = max(Max, nums[j]);
                Min = min(Min, nums[j]);
                res += Max - Min;
            }
        }
        return res;
    }
};
 // @lc code=end

