/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (42.58%)
 * Likes:    7213
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
        整体就要从选择元素的角度来理解 -- nums1选几个 nums2选几个
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //  希望在短的里面二分搜索，因此强制nums1是短的那个数组
        if(m > n)
        {
            return findMedianSortedArrays(nums2,nums1);
        }

        //  特殊情况处理 --> 有一个是空数组
        if(m == 0)
        {
            int k = (n - 1) / 2;
            return (n % 2 == 0) ? (nums2[k] + nums2[k + 1]) / 2.0 : nums2[k];
        }
        if(n == 0)
            return 0; 

        //  m n是个数 如果 + 1那无论奇偶都会落在median上 不+1就可能不落在median上
        int k = (m + n + 1) / 2;   
        int i = 0, j = 0;
        int begin = 0;
        /*
            end初始化为m可以理解为，i应当是选择的nums1的元素数量，当i = 0时，说明
            在nums1中选择了0个元素，当i = m时，说明在nums1中选择了m个元素
            如果 end初始化为m-1 那此时选不到最后一个元素 因为i最大也只有 （m + m - 1）/ 2
            也就是 i = m - 1，下标是i那你选的元素只有 i - 1也就是 0 ~ m - 1 - 1选不到m - 1
        */
        int end = m;  
        while(begin <= end)
        {
            i = (begin + end) / 2;
            j = k - i;
            //  i 选小了
            if(j > 0 && i < m && nums2[j - 1] > nums1[i])
            {
                begin = i + 1;
            }
            //  i 选大了
            else if(i > 0 && j < n && nums1[i - 1] > nums2[j])
            {
                end = i - 1;
            }
            //  选对了
            else
            {
                break;
            }
        }

        //  处理跳出循环的异常情况 否则就正常
        double left = 0;
        if (i == 0) // 说明此时nums1一个元素没选 那全在nums2中选的
        {
            left = nums2[j - 1];
        }
        else if(j == 0) //   说明此时nums2一个元素没选 那全在nums1中选的
        {
            left = nums1[i - 1];
        }
        else//  此时就是各选一部分元素
        {
            left = max(nums1[i - 1],nums2[j - 1]);
        }

        double right = 0;
        //  说明此时nums1全部选完了 因为全选完了也就最多k个元素 但是right应当是k+1
        //  所以不管怎样right都在nums2中
        if(i == m)  
        {
            right = nums2[j];
        }
        else if(j == n) //  说明此时nums2全部选完了，同理不管怎样k+1都在nums1中
        {
            right = nums1[i];
        }
        else
        {
            right = min(nums1[i],nums2[j]);
        }

        return (m + n) % 2 == 0 ? (left + right) / 2.0 : left;
    }


};
// @lc code=end

