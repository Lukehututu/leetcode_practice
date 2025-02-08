/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的质数分数
 *
 * https://leetcode.cn/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Medium (67.88%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 54.6K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * 给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 质数 组成，且其中所有整数互不相同。
 * 
 * 对于每对满足 0 <= i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。
 * 
 * 那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] ==
 * arr[j] 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [1,2,3,5], k = 3
 * 输出：[2,5]
 * 解释：已构造好的分数,排序后如下所示: 
 * 1/5, 1/3, 2/5, 1/2, 3/5, 2/3
 * 很明显第三个最小的分数是 2/5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [1,7], k = 1
 * 输出：[1,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 1000
 * 1 <= arr[i] <= 3 * 10^4
 * arr[0] == 1
 * arr[i] 是一个 质数 ，i > 0
 * arr 中的所有数字 互不相同 ，且按 严格递增 排序
 * 1 <= k <= arr.length * (arr.length - 1) / 2
 * 
 * 
 * 
 * 
 * 进阶：你可以设计并实现时间复杂度小于 O(n^2) 的算法解决此问题吗？
 * 
 */

// @lc code=start
class Solution {
public:

    int a = 0;
    int b = 0;

    //return -> 个数
    int check(vector<int>& arr, double& mid, int& size) {
        int cnt = 0;
        double large = 0;   

        for(int i = 0, j = 1; j < size; ++j) {
            //同分母时分子越大 分数越大，因此找到最后一个满足的分子，那比它小的全满足
            while(arr[i + 1] * 1.0 / arr[j] <= mid) i++;
            //拿每一组(不同分母是一组)的最大去比
            if(arr[i] * 1.0 / arr[j] <= mid) {
                cnt += (i + 1);
                if(arr[i] * 1.0 / arr[j] > large) {
                    a = arr[i];
                    b = arr[j];
                    large = a * 1.0 / b;
                }
            }
        }
        return cnt;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1;
        double mid;
        while(true) {
            mid = (left + right) / 2;
            int cnt = check(arr, mid, n);
            if(cnt > k) right = mid;
            else if(cnt < k) left = mid;
            else break;
        }
        return {a, b};
    }
};
// @lc code=end

