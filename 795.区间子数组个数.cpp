/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    //1.暴力检索 n~2~超时了
    // int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    //     int res = 0;
    //     int l = 0;
    //     bool flag = false;
    //     for(int i = 0; i < nums.size() - 1; i++) {
    //         int maxInterval = INT_MIN;
    //         flag = false;
    //         if(nums[i] > right) continue;
    //         else if(nums[i] >= left && nums[i] <= right) {
    //             maxInterval = nums[i];
    //             res++;
    //             flag = true;
    //         }
    //         for(int j = i + 1; j < nums.size(); ++j) {
    //             if(nums[j] > right) break;
    //             maxInterval = max(maxInterval, nums[j]);
    //             if(maxInterval >= left && maxInterval <= right) flag = true;
    //             res = flag ? res + 1 : res; 
    //         }
    //     }
    //     if (nums[nums.size() - 1] >= left && nums[nums.size() - 1] <= right) res++;
    //     return res;
    // }

    //2.将区间[n,m] 的个数 转化为 [-∞,m] - [-∞,n - 1] 因为范围包括了n

    int caclCount(vector<int>& nums, int bound) {
        int cnt = 0;
        int n = 0;
        for(int num : nums) {
            if(num <= bound) {
                n++;
                cnt += n;
            }
            else {
                n = 0;
            }
        }
        return cnt;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        return caclCount(nums, right) - caclCount(nums, left - 1);
    }

};
// @lc code=end

