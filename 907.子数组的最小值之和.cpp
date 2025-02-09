/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:

    //1.暴力 -- 超时
    // int sumSubarrayMins(vector<int>& arr) {
    //     int ret = 0;
    //     for(int i = 0; i < arr.size(); ++i) {
    //         int m = INT_MAX;
    //         for(int j = i; j < arr.size(); ++j) {
    //             m = min(m, arr[j]);
    //             ret += m;
    //         }
    //     }
    //     const int MOD = 1e9 + 7; // 10^9 + 7
    //     return ret % MOD;
    // }

    //2.单调栈
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> monoStack;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!monoStack.empty() && arr[i] <= arr[monoStack.back()]) {
                monoStack.pop_back();
            }
            left[i] = i - (monoStack.empty() ? -1 : monoStack.back());
            monoStack.emplace_back(i);
        }
        monoStack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!monoStack.empty() && arr[i] < arr[monoStack.back()]) {
                monoStack.pop_back();
            }
            right[i] = (monoStack.empty() ? n : monoStack.back()) - i;
            monoStack.emplace_back(i);
        }
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)left[i] * right[i] * arr[i]) % mod; 
        }
        return ans;
    }
};
// @lc code=end

