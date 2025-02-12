/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
public:

    //1.遍历两次 O(n~2~)
    // vector<int> finalPrices(vector<int>& prices) {
    //     vector<int> res(prices.begin(), prices.end());
    //     for(int i = 0; i < prices.size(); ++i) {
    //         for(int j = i + 1; j < prices.size(); ++j) {
    //             if(prices[j] <= prices[i]) {
    //                 res[i] -= prices[j];
    //                 break;
    //             }
    //         }
    //     }

    //     return res;
    // }

    //2.单调栈
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.begin(), prices.end());
        stack<pair<int, int>> st;//单增的栈
        vector<int> minus(prices.size(), 0);
        for (int i = 0; i < prices.size(); ++i) {
            while (!st.empty() && st.top().second >= prices[i]) {
                minus[st.top().first] = prices[i];
                st.pop();
            }
            st.push({i, prices[i]});
        }
    
        for (int i = 0; i < minus.size(); ++i) {
            res[i] -= minus[i];
        }
        return res;
    }
};
// @lc code=end

