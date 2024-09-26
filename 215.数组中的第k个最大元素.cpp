/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.13%)
 * Likes:    2554
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums,k,0,nums.size()-1);
        int ret = nums[nums.size() - k];
        return ret;

    }


    int Partation(vector<int>& nums,int i,int j)
    {
        int val = nums[i];
        int a = i;
        int b = j;
        while(a < b)
        {
            while(a < b && nums[b] > val)
                b--;
            if(a < b)
            {
                nums[a++] = nums[b]; 
            }

            while(a < b && nums[a] < val)
                a++;
            if(a < b)
            {
                nums[b--] = nums[a];
            }
        }
        nums[a] = val;
        return a;
    }

    void quickSort(vector<int>& nums, int k,int i,int j)
    {
        if(i >= j)
            return ;
        
        int pos = Partation(nums,i,j);
        if(pos == nums.size()  - k)
        {
            return;
        }
        else if(pos > nums.size() - k)
        {
            quickSort(nums,k,i,pos - 1);
        }
        else{
            quickSort(nums,k,pos + 1, j);
        }
    }

};
// @lc code=end

