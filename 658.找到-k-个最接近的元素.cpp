/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode.cn/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (47.82%)
 * Likes:    596
 * Dislikes: 0
 * Total Accepted:    114.2K
 * Total Submissions: 237K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 * 
 * 整数 a 比整数 b 更接近 x 需要满足：
 * 
 * 
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [1,1,2,3,4,5], k = 4, x = -1
 * 输出：[1,1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //1.找到x的index
        int index = 0, n = arr.size();
        for(; index < n; ++index) {
            if(arr[index] > x) break;
        }

        //2.x的左右两边各选k个 
        vector<int> left, right;
        int i = index - 1, j = index;
        for (int m = 0; m < k && i >= 0; ++m) {
            left.push_back(arr[i]);
            i--;
        }
        for (int m = 0; m < k && j < n; ++m) {
            right.push_back(arr[j]);
            j++;
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int num = left.size() + right.size();
        i = 0;
        j = right.size() - 1;
        //3.左边从左到右，右边从右到左
        while(i < left.size() && j >= 0 && num != k) {
            int a = abs(left[i] - x);
            int b = abs(right[j] - x);
            if(a <= b) { //剔除右边的
                right.pop_back();
                j--;
                num--;
            }
            else {//剔除左边的
                left.erase(left.begin());
                num--;
            }
        }

        //4.合并left和right
        vector<int> merged(left.size() + right.size());
        merge(left.begin(), left.end(), right.begin(), right.end(), merged.begin());
        return merged;
    }
};
// @lc code=end

