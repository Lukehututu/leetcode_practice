/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 *
 * https://leetcode.cn/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (72.17%)
 * Likes:    1231
 * Dislikes: 0
 * Total Accepted:    357.3K
 * Total Submissions: 493.6K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
 * 
 * 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
 * 
 * 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定
 * nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
 * 
 * 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出：[-1,3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * - 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
 * - 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出：[3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
 * - 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * nums1和nums2中所有整数 互不相同
 * nums1 中的所有整数同样出现在 nums2 中
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
 * 
 */

// @lc code=start
class Solution {
public:
    // 1. 暴力解法
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> res;
    //     for(int n : nums1) {
    //         int i = 0;
    //         for(; i < nums2.size(); i++) {
    //             if(nums2[i] == n) {
    //                 break;
    //             }
    //         }
    //         while(i < nums2.size() && nums2[i] <= n) {
    //             i++;
    //         }
    //         if(i == nums2.size()) {
    //             res.push_back(-1);
    //         } else {
    //             res.push_back(nums2[i]);
    //         }
    //     }
    //     return res;
    // }

    //2. 单调栈
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> hash;
        for(int i = n - 1; i >= 0; --i) {
            int num = nums2[i];
            while(!st.empty() && st.top() <= num) {
                st.pop();
            }
            hash[num] = st.empty() ? -1 :st.top();
            st.push(num);
        }

        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); ++i) {
            res[i] = hash[nums1[i]];
        }

        return res;
    }
};
// @lc code=end

